#!/bin/bash

# 8. Să se scrie un script bash care are ca argumente triplete formate dintr-un nume de fisier, un cuvant si un numar k.
# Pentru fiecare astfel de triplet, se vor afişa toate liniile fişierului care contin cuvăntul respectiv exact de k ori.

# dacă nu există argumente în linia de comandă
if [ $# -eq 0 ]
then
    echo 'Numar insuficient de argumente.'
    echo 'Utilizare:' $0 'file1 cuv1 k1 file2 cuv2 k2 ...'      # afișez modul de utilizare
    exit 1                                      				# termin execuția
fi

# parcurgem argumentele furnizate în linia de comandă
while [ ! $# -eq 0 ]
do
	FISIER=$1
    CUVANT=$2
    K=$3

    echo 'Fisier:' $FISIER 'Cuvant:' $CUVANT 'k:' $K

    NL=$(wc -l <$FISIER)									# determin numarul de linii din fisier
    echo 'Numar linii:' $NL
    for L in $(seq 1 $NL)
    do
        LINIE=$(sed -n ''$L'p' $FISIER)						# stochez continutul liniei L
        N=$(echo $LINIE | grep -o ''$CUVANT'' | wc -l)		# determin numarul N de aparitii ale cuvantului in linia L
        if [ $N -eq $K ]									# daca N este egal cu K
        then
            echo 'Linia' $L':' $LINIE						# afisez linia L
        fi
    done
	
	shift 3													# elimin tripletele care au fost deja prelucrate
done

exit 0
