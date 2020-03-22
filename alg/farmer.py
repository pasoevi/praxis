import sys
import math
from pprint import pprint

def remove_duplicates(lst):
    if len(lst) <= 1:
        return lst

    head, *tail = lst

    if len(tail) > 0:
        if head["start"] == tail[0]["start"] and head["end"] == tail[0]["end"]:
            return remove_duplicates(tail)
        else:
            return [head, *remove_duplicates(tail)]
    return [head]


l = int(input())
n = int(input())
wall = []
for i in range(n):
    st, ed = [int(j) for j in input().split()]
    section = {}
    section["start"] = st
    section["end"] = ed
    wall.append(section)

wall.sort(key = lambda x: x["start"])
for i in range(len(wall)):
    if i < len(wall) - 1 and wall[i]["end"] >= wall[i+1]["end"]:
        wall[i+1]["start"] = wall[i]["start"]
        wall[i+1]["end"] = wall[i]["end"]
    if i < len(wall) - 1 and wall[i]["start"] >= wall[i+1]["start"]:
        wall[i+1]["start"] = wall[i]["start"]

wall = remove_duplicates(wall)

unpaintedSections = []

if wall[0]["start"] > 0:
    unpainted = {}
    unpainted["start"] = 0
    unpainted["end"] = wall[0]["start"]
    unpaintedSections.append(unpainted)

if len(wall) >= 1:
    for index in range(len(wall) - 1):
        if index + 1 < len(wall) and wall[index]["end"] < wall[index+1]["start"]:
            unpainted = {}
            unpainted["start"] = wall[index]["end"]
            unpainted["end"] = wall[index+1]["start"]
            unpaintedSections.append(unpainted)

if len(wall) >= 1 and wall[-1]["end"] < l:
    unpainted = {}
    unpainted["start"] = wall[-1]["end"]
    unpainted["end"] = l
    unpaintedSections.append(unpainted)

if len(unpaintedSections) == 0:
    print("All painted")
else:
    for section in unpaintedSections:
        start = section["start"]
        end = section["end"]
        print(f"{start} {end}")
