#!/bin/bash

if [ $# -eq 0 ]
then
	echo "Numar de argumente invalid!"
	echo "EXEMPLU: $0 'fisier1' 'fisier2' ... "
	exit 1
fi

read -p "Cuvant de inlocuit: " CUVANT_IN
read -p "Cuvantul cu care se inlocuieste: " CUVANT_OUT

for FILE in $*
do
	echo "Fisierul" $FILE
	sed -i 's/'$CUVANT_IN'/'$CUVANT_OUT'/g' $FILE 
	cat $FILE	
done

exit 0
