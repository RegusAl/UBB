def numere_pare(l, lista_noua = []):
    if len(l) == 1:
        if l[0] % 2 == 1:
            lista_noua.append(l[0])
    else:
        middle = len(l) // 2
        left = numere_pare(l[:middle])
        right = numere_pare(l[middle:])
    return lista_noua

l = [1, 2, 3, 4, 5]
print(numere_pare(l))