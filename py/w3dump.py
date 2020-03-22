#!/usr/bin/env python3

"""
Grab the page found on the specified URL. Save it as a
file given as a command-line argument.

"""

import argparse
import os
import urllib.request
import gzip

parser = argparse.ArgumentParser(description="""Fetch specified
resource from http, ftp or localhost.""")
parser.add_argument('resource', metavar='URL', type=str, nargs='+',
                    help='URL of the web resource')
parser.add_argument('output', metavar='filename', type=str, 
                    help='A filename of the output file.')
parser.add_argument('-z -gzip', dest='gzip', action='store_true',
                    help='If given, the output is compressed')

args = parser.parse_args()


try:
    response = urllib.request.urlopen(''.join(args.resource))
    html = response.read()
    if args.gzip:
        with gzip.open(args.output, 'wb') as dumpfile:
            dumpfile.write(html)
    else:
        with open(args.output, 'bw') as dumpfile:
            dumpfile.write(html)
except IOError:
    print("Resource not found or unaviable")
