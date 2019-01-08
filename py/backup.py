#!/usr/bin/env python3

import argparse
import datetime
import os
import sys
import tarfile


parser = argparse.ArgumentParser(description='Backup the files specified')
parser.add_argument('files', type=str, default=[], nargs='?',
                    help='List of files to backup. Directories\
                    are processed recursively')
parser.add_argument('--filelist', '-f', metavar='file', type=argparse.FileType('r'),
                    help='A file with a list of files to backup. Directories are\
                    processed recursively')
parser.add_argument('--exclude', '-e', metavar='file', type=argparse.FileType('r'),
                    required=False,
                    help='these files will be ignored. Directories are\
                    archived recursively')
parser.add_argument('--debug', '-d', action="store_true", default=False)
parser.add_argument('--verbose', '-v', action="store_true", default=False)
parser.add_argument('--bufsize', '-b', type=int, default=10240)

args = parser.parse_args()
if args.debug == True:
    print(vars(args))

def ifexclude (filename):
    if filename in excludelist:
        return True
    return False

def addfile(file, archivefile):
    try:
        archivefile.add(file, recursive=True, exclude=ifexclude)
    except IOError as err:
        print("Skipping file ", err.filename, " : ", err.strerror)
    if args.verbose != True:
        pass
    elif file in excludelist:
        pass
    else:
        print(file)

includelist = []
excludelist = []

if args.filelist != None:
    for line in args.filelist.readlines():
        includelist.append(os.path.abspath(os.path.expanduser(line.rstrip())))

if args.exclude != None:
    for line in args.exclude.readlines():
        excludelist.append(os.path.abspath(os.path.expanduser(line.rstrip())))

date = datetime.date.today()
archivename = archivename = '.'.join((date.strftime("%B-%d-%y"),'tar.bz2'))

with tarfile.open(name=archivename, mode='w:bz2', bufsize=args.bufsize) as archivefile:
    for file in args.files.split(' ') + includelist:
        try:
            addfile(file, archivefile)
        except OSError as err:
            print("{0} : {1} [{2}].".format(err.filename, err.strerror, err.errno),
                  file=sys.stderr)


