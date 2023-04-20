#!/bin/bash

# verificare numar de argumente
if [ $# -eq 0 ]
then
	echo "Numar de argumente invalid!"
	echo "EXEMPLU: $0 nume_director"
	exit 1
fi

DIR=$1
for FILE in $(find $DIR -type f)
do
	if cat $FILE | grep -Eq '[0-9][0-9][0-9][0-9][0-9]'
	then
		NF=$(echo $FILE | sed 's@.*/@@')
		echo 'Fisier:' $NF
	fi
done

exit 0
