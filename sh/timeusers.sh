#!/bin/bash
LOGFILE="/home/sergi/log"

date >> $LOGFILE
users >> $LOGFILE
uptime | unexpand | cut --delimiter=, --fields=1 | cut --delimiter=p -f 2 | tr -d ' ' >> $LOGFILE

cat $LOGFILE | tail -n 3 