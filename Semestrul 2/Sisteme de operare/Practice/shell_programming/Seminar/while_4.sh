#!/bin/bash

if [ $# -eq 0 ]
then 
	echo "Please enter a filename!!"
	exit 1
elif !(test -r $1)
then
	echo "File is not readable!!"
	exit 1
fi

while read -r line
do
	echo $line
done	
