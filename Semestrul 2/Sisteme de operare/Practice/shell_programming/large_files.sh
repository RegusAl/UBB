#!/bin/bash

D=$1
S=$2

find $D -type -f | while read F
do
	N=`ls -l $F | awk '{print $5}'`
	if [ $N -gt $S ]
	then
		echo $F
	fi
done
