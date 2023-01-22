# 3. Determinați suma elementelor pare din listă.
def suma_elementelor(l):
    if len(l) == 1:
        if l[0] % 2 == 0:
            return l[0]
        else:
            return 0
    if len(l) == 0:
        return -1
    middle = len(l) // 2
    return suma_elementelor(l[:middle]) + suma_elementelor(l[middle:])

l = [2, 4, 6, 8]
assert suma_elementelor(l) == 20

l = [1, 3, 5]
assert suma_elementelor(l) == 0

l = [2, 4, 6, 8, 9]
assert suma_elementelor(l) == 20
