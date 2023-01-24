def cautare_binara_recursiv(el, l, left, right):
    '''
    Cauta elementul din lista
    :param el: elementul cautat
    :param l: lista de elemente (ordonate crescator)
    :param left: contorul din stanga
    :param right: contorul din dreapta
    :return: pozitia elementului sau pozitia pe care se poate insera
    '''
    if left >= right-1:
        return right
    middle = (left+right)//2
    if el <= l[middle]:
        return cautare_binara_recursiv(el, l, left, middle)
    else:
        return cautare_binara_recursiv(el, l, middle, right)

def cautare(el, l):
    '''
    Cauta elementul dintr-o lista
    :param el: elementul cautat
    :param l: lista de elemente
    :return: pozitia elementului cautat sau pozitia pe care se poate insera elementul
    '''
    if len(l) == 0:
        return 0
    if el < l[0]:
        return 0
    if el > l[len(l)-1]:
        return len(l)
    return cautare_binara_recursiv(el, l, 0, len(l))

l = [-3, 2, 4, 7, 9, 11, 15, 21, 56]
assert (cautare(2, l)) == 1
assert (cautare(9, l)) == 4
assert (cautare(11, l)) == 5
assert (cautare(15, l)) == 6
assert (cautare(1, l)) == 1
