#!/bin/bash

file_name=$1.txt
touch $file_name

for number in 1 2 3 4 5
do
	echo $number >> $file_name
done

echo "Enter a name of a file"
read nume_de_fisier
touch $nume_de_fisier

echo "Citeste in fisier: (pana la 'stop')"
read citire
echo $citire >> $nume_de_fisier
while [ $citire != "stop" ]
do
	read citire
	echo $citire >> $nume_de_fisier
done

exit 0
