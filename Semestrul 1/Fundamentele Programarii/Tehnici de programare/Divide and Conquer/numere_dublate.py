def numere_dublate(l, lista_noua = []):
    if len(l) == 1:
        lista_noua.append(l[0] * 2)
    else:
        middle = len(l) // 2
        left = numere_dublate(l[:middle])
        right = numere_dublate(l[middle:])
    return lista_noua

def numere_dublate_inplace(l, left = 0, right = -1):
    if right == -1:
        right = len(l) - 1
    if left == right:
        l[left] = l[left] * 2
    else:
        middle = (left + right) // 2
        numere_dublate_inplace(l, middle+1, right)
        numere_dublate_inplace(l, left, middle)

    return l

l = [1, 2, 3, 4]
print(numere_dublate(l))

print(numere_dublate_inplace(l))