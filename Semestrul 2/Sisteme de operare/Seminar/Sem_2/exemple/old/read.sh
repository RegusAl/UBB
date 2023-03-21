#!/bin/bash

echo -n "Introduceti un nume de fisier: "
read nume_fisier

while read -r linie
do
	echo $linie
done < $nume_fisier