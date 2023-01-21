def cautare_binara_iterativ(el, l):
    '''
    Cauta un element din lista
    :param el: elementul cautat
    :param l: lista de elemente
    :return: pozitia elementului cautat sau pozitia pe  care poate fi inserat
    '''
    if el >= l[len(l)-1]:
        return len(l)
    if el <= l[0]:
        return 0
    if len(l) == 0:
        return 0
    left = 0
    right = len(l)
    while right-left > 1:
        middle = (left+right)//2
        if el <= l[middle]:
            right = middle
        else:
            left = middle
    return right

l = [-3, 2, 4, 7, 9, 11, 15, 21, 56]
assert (cautare_binara_iterativ(2, l)) == 1
assert (cautare_binara_iterativ(9, l)) == 4
assert (cautare_binara_iterativ(11, l)) == 5
assert (cautare_binara_iterativ(15, l)) == 6
assert (cautare_binara_iterativ(1, l)) == 1