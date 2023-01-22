def is_prime(number):
    if number == 1:
        return False
    if number == 2:
        return True
    for i in range(2, number//2):
        if number % i == 0:
            return False
    return True

# 1. Determinați cel mai mare element prim din această listă.
def cel_mai_mare_element_prim(l):
    if len(l) == 0:
        return -1
    if len(l) == 1:
        if is_prime(l[0]):
            return l[0]
        else:
            return -1
    middle = len(l) // 2
    return max(cel_mai_mare_element_prim(l[:middle]), cel_mai_mare_element_prim(l[middle:]))

l = [2, 10, 11, 17, 20, 13]
print(cel_mai_mare_element_prim(l))