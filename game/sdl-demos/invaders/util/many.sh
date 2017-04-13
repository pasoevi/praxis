# !/bin/bash

scons -Q

for i in {1..15};
do
    let num=$i*10
    ./mklevel -n $num > "../assets/levels/$i.xml";
    ./mklevel -n $num > "../build/levels/$i.xml";
done
