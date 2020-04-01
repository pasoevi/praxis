import sys

l = int(input())
h = int(input())
t = input()
alphabet = []
for i in range(h):
    alphabet.append(input())

""" for c in t.upper():
    cOrd = ord(c) - ord("A")
    if cOrd > ord('Z') or cOrd < ord('A'):
        print(c, file=sys.stderr)
        print(cOrd, file=sys.stderr)

    for j in range(h):
        start = cOrd * l
        stop = start + len(t) * l
        print(str(start) + " " + str(stop), file=sys.stderr)
        for i in range(start, stop):
            if i < stop - 1:
                print(alphabet[j][i], end = '')
            else:
                print(alphabet[j][i])

 """

 for index, c in t.upper():
    cOrd = ord(c) - ord("A")
    if cOrd > ord('Z') or cOrd < ord('A'):
        cord = ord('Z') + 1

    start = cOrd * l
    stop = start + l
    for i in range(h):
        for j in range(start, stop):
            if index < len(t) - 1:
                print(alphabet[j][i], end = '')
            else:
                print(alphabet[j][i])

