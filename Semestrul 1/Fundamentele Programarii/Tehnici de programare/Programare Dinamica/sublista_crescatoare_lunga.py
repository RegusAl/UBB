# sublista crescatoare cea mai lunga cu nr din 2 cifre
def functie(lista):
    n = len(lista)
    l = []
    p = [-1] * n
    for i in range(n):
        if lista[i] > 9 and lista[i] < 100:
            l.append(1)  # orice elem din 2 cifre e in sine o secventa de lungime1
        else:
            l.append(0)
    for i in range(n):
        for j in range(i):
            if (lista[i] > 9 and lista[i] < 100) and (lista[j] > 9 and lista[j] < 100) and lista[j] < lista[i] and l[
                j] + 1 > l[i]:
                l[i] = l[j] + 1
                p[i] = j
    max = 0
    indice = 0
    rez = []
    for i in range(n):
        if l[i] > max:
            max = l[i]
            indice = i
    while indice != -1:
        rez.append(lista[indice])
        indice = p[indice]
    rez.reverse()
    if max == 0:
        rez = []
    return rez, p, l


lista = [22, 10, 16, 11, 4, 13, 14]
print(functie(lista))
