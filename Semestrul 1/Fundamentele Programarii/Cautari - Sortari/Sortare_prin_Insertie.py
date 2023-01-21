# WC = O(n^2)
# AC = O(n^2)
# BC = O(n)
def insertion_sort(l):
    '''
    Sorteaza elementele din lista
    :param l: lista de elemente
    :return: lista de elemente ordonate
    '''
    for i in range(1, len(l)):
        ind = i-1
        a = l[i]
        # inseram elementul a pe pozitia corecta
        while ind >= 0 and a < l[ind]:
            l[ind+1] = l[ind]
            ind = ind-1
        l[ind+1] = a
    return l

l = [23, 44, 12, 10, 8, 45, 9, 2, 3]
assert (insertion_sort(l)) == [2, 3, 8, 9, 10, 12, 23, 44, 45]