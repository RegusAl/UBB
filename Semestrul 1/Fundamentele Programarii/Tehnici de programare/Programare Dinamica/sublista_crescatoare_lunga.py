# sublista crescatoare cea mai lunga cu nr din 2 cifre
def functie(lista):
    n = len(lista)
    l = []
    poz = [-1] * n
    for i in range(n):
        if lista[i] < 100 and lista[i] > 9:
            l.append(1)
        else:
            l.append(0)
    for i in range (n):
        for j in range(i):
            if (lista[i] > 9 and lista[i] < 100) and (lista[j] > 9 and lista[j] < 100) and lista[j] < lista[i] and l[j] + 1 > l[i]:
                l[i] = l[j] + 1
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
        return []
    return rez


lista = [22, 10, 16, 11, 4, 13, 14]
print(functie(lista))
