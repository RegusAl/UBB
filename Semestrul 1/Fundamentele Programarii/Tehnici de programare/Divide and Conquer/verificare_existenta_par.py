def exista_par(l):
    if len(l) == 0:
        return -1
    if len(l) == 1:
        if l[0] % 2 == 0:
            return True
        return False
    middle = len(l)//2
    return exista_par(l[:middle]) or exista_par(l[middle:])

l = [1, 3, 2, 5]
print(exista_par(l))