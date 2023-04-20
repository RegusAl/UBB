#!/bin/bash

if [ ! $(($#%3)) -eq 0 ] || [ $# -eq 0 ]
then
	echo "Numar invalid de argumente"
	exit 1
fi
	
while [ ! $# -eq 0 ]
do
	FISIER=$1
	CUVANT=$2
	K=$3
	
	echo "Fisier: $FISIER | Cuvant: $CUVANT | Numar: $K |"
	
	NL=$(wc -l <$FISIER)
	for L in $(seq 1 $NL)
	do
		LINIE=$(sed -n ''$L'p' $FISIER)
		N=$(echo $LINIE | grep -o "$CUVANT" | wc -l)
		if [ $N -eq $K ]
		then
			echo "Linia $L : $LINIE"
		fi
	done
	shift 3
done

exit 0
