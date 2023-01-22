# 2. Verificați dacă în listă există cel puțin un element impar.
def verificare_element_impar(l):
    if len(l) == 0:
        return False
    if len(l) == 1:
        if l[0] % 2 == 1:
            return True
        else:
            return False
    middle = len(l) // 2
    return verificare_element_impar(l[:middle]) or verificare_element_impar(l[middle:])


l = [2, 4, 6, 8]
assert verificare_element_impar(l) == False

l = [1, 3, 4]
assert verificare_element_impar(l) == True

l = [2, 4, 6, 8, 9]
assert verificare_element_impar(l) == True
