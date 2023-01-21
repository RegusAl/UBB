# AC = BC = WC = O(n^2)
def selection_sort(l):
    '''
    Sorteaza elementele din lista
    :param l: lista de elemente
    :return: lista de elemente sortate
    '''
    for i in range(0, len(l)-1):
        ind = i
        # cauta cel mai mic element din lista
        for j in range (i+1, len(l)):
            if l[j] < l[ind]:
                ind = j
        if i < ind:
            aux = l[i]
            l[i] = l[ind]
            l[ind] = aux
    return l

l = [23, 44, 12, 10, 8, 45, 9, 2, 3]
assert (selection_sort(l)) == [2, 3, 8, 9, 10, 12, 23, 44, 45]

def direct_selection_sort(l):
    '''
    Sorteaza elementele din lista
    :param l: lista de elemente
    :return: lista de elemente sortate
    '''
    for i in range(0, len(l)-1):
        # cauta cel mai mic element
        for j in range (i+1, len(l)):
            if l[j] < l[i]:
                l[j], l[i] = l[i], l[j]
    return l

l = [23, 44, 12, 10, 8, 45, 9, 2, 3]
assert (selection_sort(l)) == [2, 3, 8, 9, 10, 12, 23, 44, 45]