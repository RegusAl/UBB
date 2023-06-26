#!/bin/bash
var=$1
for x in $(seq 1 $var) 
do
	touch file_$x.txt
	sed -n ''$x',+5p' /etc/passwd > file_$x.txt
done

#echo $var
exit 0
