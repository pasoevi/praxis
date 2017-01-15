import os
import itertools
vocab = open("vocabulary.txt", "r")
wordlist = set()
for word in vocab.readlines():
    wordlist.add(word.strip())
def anagram(letterset):
    for word in itertools.permutations(letterset):
        word = ''.join(word)
        if word in wordlist:
            print(word)
anagram(input("Please, enter letters: ")            
