def numarul_de_numere(l):
    if len(l) == 0:
        return 0
    if len(l) == 1:
        if l[0] % 2 == 1:
            return 1
        return 0
    middle = len(l) // 2
    return numarul_de_numere(l[:middle]) + numarul_de_numere(l[middle:])

l = [1, 2, 3, 4, 2]
assert numarul_de_numere(l) == 2

print(numarul_de_numere(l))