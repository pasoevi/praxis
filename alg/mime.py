import os
import sys
import math
import pprint

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())  # Number of elements which make up the association table.
q = int(input())  # Number Q of file names to be analyzed.
mimeTypes = dict()
for i in range(n):
    ext, mt = input().split()
    mimeTypes[ext.lower()] = mt


for i in range(q):
    fname = input()  # One file name per line.
    filename, extension = os.path.splitext(fname)
    # Allow files with empty name before extension
    if not extension and filename.count(".") == len(filename[0:filename.rfind(".")+1]):
        extension = filename[filename.rfind("."):]

    extension = extension[1:].lower() if len(extension) > 0 else "kjlkj"

    if extension in mimeTypes.keys():
        print(mimeTypes[extension])
    else:
        print("UNKNOWN")
