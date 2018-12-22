#!/usr/bin/env python3

from collections import deque

graph = {}
graph["you"] = ["alice", "bob", "claire"]
graph["bob"] = ["anuj", "peggy"]
graph["alice"] = ["peggy"]
graph["claire"] = ["thom", "jonny"]
graph["anuj"] = []
graph["peggy"] = []
graph["thom"] = []
graph["jonny"] = []



def person_is_seller(person):
    return person[-1] == 'm'

def find_closest_seller(network):
    search_queue = deque()
    search_queue += graph["you"]
    searched = []

    while search_queue:
        person = search_queue.popleft()
        if not person in searched:
            if person_is_seller(person):
                return person
            else:
                search_queue += graph[person]
                searched.append(person)
    return None

magno_seller = find_closest_seller(graph)
if magno_seller is not None:
    print("You can buy mangos from " + magno_seller)
else:
    print("You have no mango sellers in your network")