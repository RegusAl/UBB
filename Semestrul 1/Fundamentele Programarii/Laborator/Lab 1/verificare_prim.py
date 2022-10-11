# Verificați daca un număr citit de la tastatura este prim

from pickle import FALSE, TRUE


numar = int(input("Numarul este:"))

# functie ce verifica daca un numar este prim
def prim(n):
    if(n<=1):
        return FALSE
    else:
        for i in range(2, n):
            if n % i == 0:
                return FALSE
    return TRUE

if prim(numar)==TRUE:
    print("Numarul", numar, "este prim")
else:
    print("Numarul", numar, "nu este prim")