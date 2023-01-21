# Cautare Secventiala
# BC = AC = WC = O(n)
def cautare_secventiala(el, l):
    '''
    Cauta elementul din lista
    :param el: elementul cautat
    :param l: lista de elemente
    :return: pozitia elementului sau -1 daca nu exista elementul cautat in lista
    '''
    poz = -1
    for i in range(0, len(l)):
        if el ==l[i]:
            poz = i
    return poz

l = [3, 1, 0, -2, 5, 9, 6]
assert (cautare_secventiala(0, l)) == 2

# Cautare Secventiala (cauta succesiv si returneaza pozitia atunci cand o gaseste)
# BC = O(1) - cand elementul cautat este pe prima pozitie
# AC = O(n)
# WC = O(n) - cand elementul cautat este pe ultima pozitie din lista
def cautare_secventiala_succesiv(el, l):
    '''
    Cauta elementul din lista
    :param el: elementul cautat
    :param l: lista de elemente
    :return: pozitia elementului sau -1 daca nu exista elementul in lista
    '''
    i = 0
    while i<len(l) and el != l[i]:
        i += 1
    if i<len(l):
        return i
    return -1

l = [3, 1, 0, -2, 5, 9, 6]
assert (cautare_secventiala_succesiv(0, l)) == 2
