#!/bin/bash

if [ $# -eq 0 ]
	then
	echo "Trebuie sa dati un nume de fisier."
	exit 1
elif !(test -r $1)
	then
	echo "Fisierul $1 nu există"
	exit 1
fi

while read -r linie
do
	echo $linie
done
