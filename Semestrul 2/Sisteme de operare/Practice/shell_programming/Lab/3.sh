#!/bin/bash

# verficare numar de argumente
if [ $# -eq 0 ]
then
	echo "Numarul de argumente este invalid!"
	echo "Exemplu: $0 'nume_director'"
	exit 1
fi

DIR=$1
NR=0
SUM=0

for FILE in $(find $DIR -type f | sort)
do
	if file $FILE | grep -q 'ASCII text$'
	then
		echo -n "Fisier: "; echo $FILE | sed 's@.*/@@'
		NL=$(cat $FILE | wc -l)
		echo "Numarul liniilor: $NL"
		SUM=$(($SUM+$NL))
		NR=$(($NR+1))
	fi
done

echo "----------------------------"
echo "SUMA liniilor este $SUM"
echo "NUMARUL fisierelor este $NR"

echo "MEDIA este $(($SUM/$NR))"
