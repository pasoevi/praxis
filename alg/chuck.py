import sys
import math
import pprint

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

# message = input()
message = "CC"
binMsg = ''
for char in message:
    binMsg += '{0:07b}'.format(ord(char))

encodedMsg = ''
for bit in binMsg:
    if (len(encodedMsg) == 0) or (encodedMsg[-1] == bit):
        encodedMsg += bit
    else:
        encodedMsg += " " + bit

encodedMsg = encodedMsg.split(" ")
chuck = ""
for series in encodedMsg:
    if '1' in series:
        chuck += "0 "
    else:
        chuck += "00 "
    chuck += "0" * len(series)
    chuck += " "

pprint.pprint(chuck.rstrip())
