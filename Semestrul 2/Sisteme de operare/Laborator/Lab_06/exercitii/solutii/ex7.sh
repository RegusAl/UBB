#!/bin/bash

# 7. Să se scrie un script bash care primește ca argumente oricâte nume de fișiere.
# Scriptul va citi de la tastatură două cuvinte și va înlocui TOATE aparițiile primului cuvânt
# cu cel de-al doilea în fiecare fișier furnizat ca argument.

# dacă nu există argumente în linia de comandă
if [ $# -eq 0 ]
then
    echo 'Numar insuficient de argumente.'
    echo 'Utilizare:' $0 'file1 file2 ...'      # afișez modul de utilizare
    exit 1                                      # termin execuția
fi

read -p "Primul cuvant: " CUV1
read -p "Al doilea cuvant: " CUV2

for FISIER in $*
do
	echo 'Fisier:' $FISIER
	sed -i 's/'$CUV1'/'$CUV2'/g' $FISIER			# inlocuiesc TOATE aparițiile primului cuvânt cu cel de-al doilea
done

exit 0
