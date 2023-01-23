def maximul(l):
    if len(l) == 0:
        return -1
    if len(l) == 1:
        return l[0]
    middle = len(l) // 2
    return max(maximul(l[:middle]), maximul(l[middle:]))

L = [2,8,4,1,4,5,6,7]
print(maximul(L))