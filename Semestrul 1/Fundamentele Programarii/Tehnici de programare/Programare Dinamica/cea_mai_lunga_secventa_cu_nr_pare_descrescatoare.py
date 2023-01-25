# Cea mai lunga secventa de numere impare descrescatoare
# Folosim doi vectori: l si p
# l e folosit pentru a determina secventa maxima care se termina cu fiecare element
# p e folosit pentru a determina elementul anterior din secventa
def functie(lista):
    n = len(lista)
    l = []
    poz = [-1] * n
    for i in range(n):
        if lista[i] % 2 == 0:
            l.append(1)
        else:
            l.append(0)
    for i in range(n):
        for j in range(i):
            if lista[i] % 2 == 0 and lista[j] % 2 == 0 and lista[i] < lista[j] and l[j] + 1 > l[i]:
                l[i] = l[j]+1
                poz[i] = j
    max = 0
    indice = 0
    rez = []
    for i in range(n):
        if l[i] > max:
            max = l[i]
            indice = i
    while indice != -1:
        rez.append(lista[indice])
        indice = poz[indice]
    rez.reverse()
    if max == 0:
        rez = []
    return rez, poz, l



lista = [2, 12, 3, 6, 14, 3, 4, 7, 2]
print(functie(lista))