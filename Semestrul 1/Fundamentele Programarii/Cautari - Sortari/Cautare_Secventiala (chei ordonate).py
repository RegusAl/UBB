# Cautare Secventiala (lista ordonata)
# BC = O(1)
# AC = O(n)
# WC = O(n)
def cautare_secventiala(el, l):
    '''
    Cauta elementul din lista
    :param el: elementul cautat
    :param l: lista de elemente
    :return: pozitia elementului gasit sau pozitia pe care se poate insera
    '''
    if len(l) == 0:
        return 0
    poz = -1
    for i in range(0, len(l)):
        if el > l[i]:
            poz = i+1
    if poz == -1:
        return 0
    return poz

l = [1, 3, 5, 7, 12, 45, 88, 90]
assert (cautare_secventiala(-1, l)) == 0
assert (cautare_secventiala(2, l)) == 1
assert (cautare_secventiala(3, l)) == 1
assert (cautare_secventiala(100, l)) == 8

# Cautare Secventiala Succesiva (lista ordonata)
# BC = O(1)
# AC = O(n)
# WC = O(n)
def cautare_secventiala_succesiv(el, l):
    '''
    Cauta elementul din lista
    :param el: elementul cautat
    :param l: lista de elemente
    :return: pozitia elementului gaasit sau pozitia pe care se poate insera
    '''
    if len(l) == 0:
        return 0
    if el > l[len(l)-1]:
        return len(l)
    i = 0
    while i < len(l) and el > l[i]:
        i += 1
    return i

l = [1, 3, 5, 7, 12, 45, 88, 90]
assert (cautare_secventiala_succesiv(2, l)) == 1
assert (cautare_secventiala_succesiv(3, l)) == 1
assert (cautare_secventiala_succesiv(100, l)) == 8


