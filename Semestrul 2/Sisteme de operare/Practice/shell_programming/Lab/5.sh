#!/bin/bash

if [ $# -eq 0 ]
then
	echo "Numar de argumente  invalid!"
	echo "EXEMPLU: $0 'nume_fisier / nume_director'"
	exit 1
fi

for A in $*
do
	if [ -d $A ]
	then
		echo "$A este director."
		NF=$(find $A -type f | grep -c ".")
		echo "Directorul contine $NF fisiere."
		echo "--------------"		
	elif [ -f $A ]
	then	
		echo "$A este fisier"
		NC=$(wc -m <$A)
		echo "Numarul de caractere: $NC."
		NL=$(wc -l <$A)
		echo "Numarul de linii: $NL."
		echo "--------------"
	else
		echo "$A nu este nici director, nici fisier."
		echo "--------------"
	fi
done
