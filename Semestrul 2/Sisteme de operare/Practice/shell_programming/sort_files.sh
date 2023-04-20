#!/bin/bash

for i in $*
do
	if [ -f $i ]
	then
		du -b $i
	fi
done | sort -n
