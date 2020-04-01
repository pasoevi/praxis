#!/usr/bin/env python3
import itertools
import cProfile
import sys
import os
import pprint
import argparse

dictionary = set()


class LettersetException(Exception):
    pass

def anagram(letterset, dictionary, length=None):
    if len(letterset) == 0:
        raise LettersetException

    for word in itertools.permutations(letterset, length):
        word = ''.join(word)   # make str from tuple word
        if word in dictionary:
            yield word

def perm(letterset, length=None):
    if len(letterset)== 0:
        raise LettersetException
    perms = {''.join(word) for word in itertools.permutations(letterset, length)}
    return perms
        
        
if __name__=='__main__':

    parser = argparse.ArgumentParser(
        "Prints all the anagrams for the given letterset.")
    parser.add_argument('letterset', metavar='letterset',
                        type=str, help='set of letters from which you want to combine words')
    parser.add_argument('length', metavar='wordlength',
                        type=int, help='Return the words of this length only.')
    parser.add_argument('-d --wordlist', dest='wordlist', type=argparse.FileType('r'),
                        default="/usr/share/dict/word.list", help='Set a custom dictionary')
    parser.add_argument('-p --up-to',
                        help='If true, the length is the maximum length. Only works with -d.',
                        action='store_true')

    args = parser.parse_args()
    
    try: 
        for line in args.wordlist.readlines():
            dictionary.add(line.strip())
    except IOError:
        print("The dictionary file doesn't exist in the location you've pointed to")
        raise SystemExit()
    anag = anagram(args.letterset, dictionary, args.length)


    assert dictionary is not None
    anagrams = []
    for word in anag:
        anagrams.append(word)
    pprint.pprint(anagrams)
    print(len(anagrams))
    cProfile.run(perm(args.letterset, args.length))
    anagrams =set(dictionary).intersection(perm(args.letterset, args.length))
    print(anagrams)
