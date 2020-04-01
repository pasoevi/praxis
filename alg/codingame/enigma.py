import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

def caesar_encode(string, shift):
    result = ""
    current_shift = shift
    for c in string:
        result += chr((ord(c) + current_shift - 65) % 26 + 65)
        current_shift = current_shift + 1 if current_shift < 25 else 0
    return result

def caesar_decode(string, shift):
    result = ""
    current_shift = shift
    for c in string:
        result += chr((ord(c) - current_shift - 65) % 26 + 65)
        current_shift = current_shift + 1 if current_shift < 25 else 0
    return result

operation = input()
pseudo_random_number = int(input())
rotors = []
for i in range(3):
    rotors.append(input())

message = input()

def enigma_encode(string, rotors, shift):
    rotation_result = list(caesar_encode(string, shift))
    for rotor in rotors:
        rotation_result = list(map(lambda c: rotor[ord(c) - 65], rotation_result))
    return "".join(rotation_result)
    
def enigma_decode(string, rotors, shift):
    rotors = list(reversed(rotors))
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    rotation_result = list(string)
    for rotor in rotors:
        rotation_result = list(map(lambda c: alphabet[rotor.find(c)], rotation_result))
    return "".join(list(caesar_decode(rotation_result, shift)))

def enigma(operation, string, rotors, shift):
    if operation[0] == "D":
        return enigma_decode(string, rotors, shift)
    return enigma_encode(string, rotors, shift)

print(enigma(operation, message, rotors, pseudo_random_number))