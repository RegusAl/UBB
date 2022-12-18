# Bubble Sort
def bubble_sort(list, key = lambda x: x, cmp = lambda x, y: x>y, reverse = False):
    '''
    Functie de sortare folosind metoda bulelor
    :param list: lista ce trebuie sortata
    :param key: cheia dupa care se sorteaza
    :param cmp: functia de comparare
    :param reverse: True sau False daca lista trebuie sa fie sortata descrescator sau crescator
    :return: -
    '''
    ok = False
    while ok is False:
        ok = True
        for index in range(len(list)-1):
            if cmp(key(list[index]), key(list[index+1])):
                list[index], list[index+1] = list[index+1], list[index]
                ok = False
    if reverse == True:
        list.reverse()

# Shell Sort
def shell_sort(list, key = lambda x: x, cmp = lambda x, y: x>y, reverse = False):
    '''
    Functia de sortare folosind metoda 'shell'
    :param list: lista de sortat
    :param key: cheia dupa care se sorteaza
    :param cmp: functia de comparare
    :param reverse: True sau False daca lista trebuie sa fie sortata descrescator sau crescator
    :return: -
    '''
    n = len(list)
    gap = n // 2
    while gap>0:
        j = gap
        while j<n:
            i = j-gap
            while i>=0:
                if list[i+gap]>list[i]:
                    break
                else:
                    list[i+gap], list[i] = list[i], list[i+gap]
                i = i - gap
            j += 1
        gap = gap // 2
    if reverse == True:
        list.reverse()
