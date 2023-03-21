#!/bin/bash

# numaram fisierele
count=`ls -al | wc -l`

# Scadem intrarile corespunzatoare directorului curent (.) si directorului parinte (..)
echo "Numarul de fisiere: " $(($count-2))