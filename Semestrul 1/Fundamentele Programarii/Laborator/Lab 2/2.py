# Se da data nașterii (zi/luna/an), determinați vârsta persoanei in zile.

import datetime

current_date = datetime.datetime.now()

print(current_date.day, current_date.month, current_date.year)
months = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

zile = int(input("Ziua:"))
luna = int(input("Luna:"))
anul = int(input("Anul:"))

zileTotal = 0

anCurent = current_date.year
lunaCurenta = current_date.month
ziCurenta = current_date.day

nrAni = 0
if anCurent-1>anul+1:
    nrAni = anCurent-1-anul+1

i = luna+1
while i<=12:
    zileTotal = zileTotal + months[i]
    i = i+1

lunaCurenta = lunaCurenta-1
while lunaCurenta>0:
    zileTotal = zileTotal + months[lunaCurenta]
    lunaCurenta = lunaCurenta-1

zileTotal = zileTotal + ziCurenta + zile + nrAni*365

print(zileTotal)
    
