#!/bin/bash

if [ $# -eq 0 ]
then
	echo "Numar de argumente invalid!"
fi	

for file in $@; do
  # folosim comanda grep pentru a număra numărul de apariții al fiecărei linii
  # apoi sortăm rezultatele în ordine descrescătoare și ne limităm la prima linie folosind comanda head
  # care va fi linia cu cele mai multe apariții
    most_common_line=$(grep -v "^$" "$file" | sort | uniq -c | sort -rn | head -n 1) 
  # afișăm numele fișierului și linia care apare cel mai des
  echo "$file: $most_common_line"
done
