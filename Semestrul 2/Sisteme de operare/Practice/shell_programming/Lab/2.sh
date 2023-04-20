#!/bin/bash

# verificam daca numarul de argumente este valid
if [ $# -eq 0 ]
then
	echo "Numar insuficient de argumente"
	echo "Exemplu: $0 'nume_director'"
	exit 1
fi

# primul argument este directorul
DIR=$1

for FILE in $(find $DIR -type f | sort)
do
	if file $FILE | grep -q  'ASCII text$'                 # verificam tipul fisierului
	then 
		echo -n "Fisier: "; echo $FILE | sed 's@.*/@@' # afisam numele fisierului
		NL=$(cat $FILE | wc -l)                        # NL = numarul de linii a fisierului deschis
		if [ $NL -lt 6 ]
		then
			cat -n $FILE			     
		else
			echo "HEAD"
			head -n 3 $FILE	
			echo "TAIL"
			tail -n 3 $FILE
		fi
	fi
	echo "--------"
done

exit 0	
