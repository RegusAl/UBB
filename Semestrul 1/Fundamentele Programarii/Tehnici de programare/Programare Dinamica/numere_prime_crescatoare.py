def isPrime(param):
    for i in range(2, param//2):
        if param % i == 0:
            return False
    return True

def functie(lista):
    n = len(lista)
    l = []
    poz = [-1] * n
    for i in range(n):
        if isPrime(lista[i]):
            l.append(1)
        else:
            l.append(0)
    for i in range(n):
        for j in range(i):
            if isPrime(lista[i]) and isPrime(lista[j]) and lista[j] < lista[i] and l[j] + 1 > l[i]:
                l[i] = l[j]+1
                poz[i] = j
    rez = []
    max = 0
    indice = 0
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
    return rez

l = [21, 2, 11, 3, 4, 7, 13]
print(functie(l))