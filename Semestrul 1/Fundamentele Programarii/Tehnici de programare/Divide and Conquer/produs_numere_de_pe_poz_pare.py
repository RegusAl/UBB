def produs(l, left = 0, right = -1):
    if right == -1:
        right = len(l)-1
    if right == left:
        if left % 2 == 0:
            return l[left]
        else:
            return 1
    middle = (left+right) // 2
    return produs(l, left, middle) * produs(l, middle+1, right)

l = [1, 2, 3, 4]
print(produs(l))