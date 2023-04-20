#!/bin/bash

# 6. Să se scrie un script bash care primește ca argumente oricâte nume de fișiere.
# Scriptul va citi de la tastatură un cuvânt, va determina și afișa numărul de apariţii
# ale cuvântului în fiecare fișier furnizat ca argument.

# dacă nu există argumente în linia de comandă
if [ $# -eq 0 ]
then
    echo 'Numar insuficient de argumente.'
    echo 'Utilizare:' $0 'file1 file2 ...'      # afișez modul de utilizare
    exit 1                                      # termin execuția
fi

# prima solutie
# -------------------------------------------------------------------------------------

#read -p "Cuvant: " CUVANT

#for FISIER in $*
#do
#   APARITII=$(cat $FISIER | grep -o '\b'$CUVANT'\b' | wc -l)
#   echo 'Fisier:' $FISIER 'Cuvant:' $CUVANT 'Nr. aparitii:' $APARITII
#done


# a doua solutie
# -------------------------------------------------------------------------------------

read -p "Cuvant: " CUVANT

for FISIER in $*
do
    APARITII=0
    CUVINTE=$(cat $FISIER)
    for CUV in $CUVINTE
    do
        echo $CUV
        if [ "$CUV" == "$CUVANT" ]
        then
            APARITII=$((APARITII+1))
        fi
    done

    echo 'Fisier:' $FISIER 'Cuvant:' $CUVANT 'Nr. aparitii:' $APARITII

done

exit 0
