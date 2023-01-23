def inversare(l):
    if len(l) == 0:
        return -1
    if len(l) == 1:
        return l
    middle = len(l) // 2
    st = inversare(l[:middle])
    dr = inversare(l[middle:])
    return dr + st

l = [1, 2, 3, 4]
print(inversare(l))