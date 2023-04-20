#!/bin/bash

if [ $# -eq 0 ]
then
	echo "Numarul de argumente este invalid!"
	echo "EXEMPLU: $0 'fisier1' 'fisier2' ... "
	exit 1
fi

read -p "Cuvant: " CUVANT

for FILE in $* 
do
	APARITII=0
	CUVINTE=$(cat $FILE)
	for C in $CUVINTE
	do
		#echo $C
		if [ $C == $CUVANT ]
		then
			APARITII=$((APARITII+1))
		fi
	done	
	echo "In fisierul $FILE cuvantul $CUVANT apare de $APARITII ori."
done
