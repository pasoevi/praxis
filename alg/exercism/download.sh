#!/bin/bash

# "exercism download all" for specific tracks

function eda() {
  for trackname in "$@"; do
    echo https://exercism.io/tracks/$trackname/exercises
    curl -LS https://exercism.io/tracks/$trackname/exercises | grep "/tracks/$trackname/exercises/" | awk '{print $3}' | cut -d/ -f5 | cut -d\" -f1 > exercises.txt
    while read in; do exercism download --exercise="$in" --track=$trackname; done < exercises.txt
    rm exercises.txt
  done
}
