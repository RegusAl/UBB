def numarul_de_numere_pozitive(l):
    if len(l) == 0:
        return -1
    if len(l) == 1:
        if l[0] >= 0:
            return 1
        return 0
    middle = len(l) // 2
    return numarul_de_numere_pozitive(l[:middle]) + numarul_de_numere_pozitive(l[middle:])

l = [1, 2, -7, -89, -1, 4, -67]
print(numarul_de_numere_pozitive(l))