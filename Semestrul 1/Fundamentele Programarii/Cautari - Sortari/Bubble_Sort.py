# Bubble Sort - in-place
# BC = O(n)
# AC = O(n^2)
# WC = O(n^2)
def bubble_sort_1(l):
    sorted = False
    while not sorted:
        sorted = True
        for i in range(len(l)-1):
            if l[i+1] < l[i]:
                l[i], l[i+1] = l[i+1], l[i]
                sorted = False
    return l

l = [23, 44, 12, 10, 8, 45, 9, 2, 3]
assert (bubble_sort_1(l)) == [2, 3, 8, 9, 10, 12, 23, 44, 45]

def bubble_sort_2(l):
    for j in range (1, len(l)):
        for i in range(0, len(l)-1):
            if l[i+1] < l[i]:
                l[i], l[i+1] = l[i+1], l[i]
    return l

l = [23, 44, 12, 10, 8, 45, 9, 2, 3]
assert (bubble_sort_2(l)) == [2, 3, 8, 9, 10, 12, 23, 44, 45]
