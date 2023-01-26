def divide(l, lista = []):
    if len(l) == 1:
        if l[0] % 2 == 1:
            return lista.append(l[0])
        else:
            return
    middle = len(l) // 2
    divide(l[:middle], lista)
    divide(l[middle:], lista)
    return lista


print(divide([1, 2, 3, 4]))