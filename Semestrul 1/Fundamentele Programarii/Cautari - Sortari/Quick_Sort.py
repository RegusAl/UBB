# Quick Sort
def partition(l, left, right):
    pivot = l[left]
    i = left
    j = right
    while i != j:
        while l[j] >= pivot and i < j:
            j -= 1
        l[i] = l[j]
        while l[i] <= pivot and i < j:
            i += 1
        l[j] = l[i]
    l[i] = pivot
    return i

def quickSortRec(l, left, right):
    pos = partition(l, left, right)
    # se ordoneaza partea stanga a listei
    if left < pos - 1:
        quickSortRec(l, left, pos-1)
    # se ordoneaza partea dreapta a listei
    if pos+1 < right:
        quickSortRec(l, pos+1, right)

l = [23, 44, 12, 10, 8, 45, 9, 2, 3]
quickSortRec(l, 0, len(l)-1)
assert l == [2, 3, 8, 9, 10, 12, 23, 44, 45]
