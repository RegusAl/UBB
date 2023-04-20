#!/bin/bash

# verificam daca numarul de argumente este valid
if [ $# -eq 0 ]
then
	echo "Numar de argumente invalid! "
	echo "Exemplu: $0 'numar_natural' "
	exit 1
fi

A=1
F=$1
F=$((F+1))
while [ ! $A -eq $F ]  
do
	echo "fisierul file_${A}.txt a fost creat!"
	touch "file_${A}.txt"
	sed -n ''$A',+5p' /etc/passwd >"file_$A.txt" 
	A=$((A+1))
done

exit 1
