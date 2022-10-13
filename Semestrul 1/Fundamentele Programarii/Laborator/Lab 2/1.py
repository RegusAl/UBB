# Găsiți primul număr prim mai mare decât un număr dat.

from pickle import FALSE, TRUE

# functia prim ce returneaza TRUE daca numarul n este prim
def prim(n):
    if n<=1:
        return FALSE
    else:
        for i in range(2, n):
            if n%i==0:
                return FALSE
    return TRUE

# citirea numarului
numar = int(input("Numar:"))
numar = numar+1

# daca 'numar' este prim va iesi din while
while prim(numar)==FALSE:
    numar = numar+1

print(numar)
