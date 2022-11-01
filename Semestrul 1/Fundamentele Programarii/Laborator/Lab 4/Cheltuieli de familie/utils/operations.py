#from domain.cheltuiala import creeaza_cheltuiala
from utils.get_and_set import get_zi, get_tip, get_suma

# Adauga cheltuiala

def creeaza_cheltuiala(zi, suma, tip):
    '''
    Creeaza o cheltuiala
    :param zi: int
    :param suma: float
    :param tip: string
    :return: cheltuiala
    '''
    return [zi, suma, tip]

def adauga_cheltuiala(lista_cheltuieli, cheltuieli):
    '''
    Adauga o cheltuiala la lista data
    :param lista_cheltuieli: lista de cheltuieli
    :type lista_cheltuieli: list
    :param cheltuieli: cheltuiala ce trebuie adaugata
    :type cheltuieli: dict
    :return: - (lista de cheltuieli se modifica prin adaugarea unei cheltuieli)
    '''
    lista_cheltuieli.append(cheltuieli)

def actualizare_cheltuiala(lista_cheltuieli, zi, suma, tip, cheltuiala):
   '''
   Actualizeaza o cheltuiala pe baza zilei, a sumei si a tipului
   :param lista_cheltuieli: lista de cheltuieli (list)
   :param zi: ziua pe care vrea utilizatorul sa o schimbe (int)
   :param suma: suma pe care vrea utilizatorul sa o schimbe (float)
   :param tip: tipul de cheltuiala pe care vrea utilizatorul sa o schimbe (string)
   :return: o noua cheltuiala actualizata
   '''
   cheltuiala_noua = {}
   for el in lista_cheltuieli:
       if el == cheltuiala:
           lista_cheltuieli.remove(cheltuiala)
           cheltuiala_noua = creeaza_cheltuiala(zi, suma, tip)
           break
   return cheltuiala_noua



# Stergere

def stergere_cheltuiala_zi(lista_cheltuieli, ziua):
    '''
    Sterge cheltuiala/cheltuielile din ziua respectiva
    :param lista_cheltuieli: list
    :param ziua: int
    :return: - (se sterg cheltuielile din ziua respectiva)
    '''
    i = 0
    while i < len(lista_cheltuieli):
        if get_zi(lista_cheltuieli[i]) == ziua:
            del lista_cheltuieli[i]
        i += 1

def stergere_cheltuiala_interval(lista_cheltuieli, zi_inceput, zi_sfarsit):
    '''
    Sterge cheltuielile din intervalul de zile dat
    :param lista_cheltuieli: list
    :param zi_inceput: ziua din care se incepe stergerea (int)
    :param zi_sfarsit: ziua in care se termina stergerea (int)
    :return: - (se sterg cheltuielile din intervalul de timp dat)
    '''
    i = 0
    while i < len(lista_cheltuieli):
        if get_zi(lista_cheltuieli[i]) >= zi_inceput and get_zi(lista_cheltuieli[i]) <= zi_sfarsit:
            del lista_cheltuieli[i]
        else:
            i += 1

def stergere_cheltuiala_tip(lista_cheltuieli, tipul):
    '''
    Sterge din lista cu cheltuieli, cheltuielile de un anumit tip dat de utilizator
    :param lista_cheltuieli: lista cu cheltuieli (list)
    :param tipul: Tipul de cheltuiala (string)
    :return: Sterge cheltuielile de un anumit tip
    '''
    i = 0
    while i < len(lista_cheltuieli):
        if get_tip(lista_cheltuieli[i]) == tipul:
            del lista_cheltuieli[i]
        else:
            i += 1

# Cautari

def cautare_cheltuieli_suma(lista_cheltuieli, suma):
    '''
    Afiseaza cheltuielile din lista de cheltuili ce au suma exacta sau mai mare dacat suma data de utulizator
    :param lista_cheltuieli: lista de cheltuieli (list)
    :param suma: suma data de utilizator (float)
    :return: - Afisare a cheltuielilor
    '''
    lista_aux = []
    for el in lista_cheltuieli:
        if get_suma(el) >= suma:
            lista_aux.append(el)
    return lista_aux

def cautare_cheltuieli_zi_suma(lista_cheltuieli, zi, suma):
    '''
    Cauta si pune intr-o lista auxiliara elementele ce indeplinesc conditia
    :param lista_cheltuieli: lista de cheltuieli (list)
    :param zi: ziua pana la care se tiparesc cheltuielile (int)
    :param suma: suma pana la care se tiparesc cheltuielile (float)
    :return: returneaza lista cu cheltuielile ce indeplinesc conditia
    '''
    lista_aux = []
    for el in lista_cheltuieli:
        if zi > get_zi(el) and suma > get_suma(el):
            lista_aux.append(el)
    return lista_aux

def cautare_cheltuieli_tip(lista_cheltuieli, tip):
    '''
    Tipareste toate cheltuielile de un anumit tip
    :param lista_cheltuieli: lista de cheltuieli (list)
    :param tip: tipul de cheltuiala (string)
    :return: Afiseaza cheltuielile de un anumit tip
    '''
    lista_aux = []
    for el in lista_cheltuieli:
        if get_tip(el) == tip:
            lista_aux.append(el)
    return lista_aux

# Rapoarte

def raport_suma_din_tip(lista_cheltuieli, tip):
    '''
    Tipareste suma totala pentru un anumit tip de cheltuiala
    :param lista_cheltuieli: lista de cheltuieli (list)
    :param tip: tipul de cheltuiala (string)
    :return: returneaza suma totala
    '''
    suma = 0
    for el in lista_cheltuieli:
        if get_tip(el) == tip:
            suma += get_suma(el)
    return suma

def raport_suma_max(lista_cheltuieli):
    '''
    Returneaza ziua in care suma cheltuita este maxima
    :param lista_cheltuieli: lista de cheltuieli (list)
    :return: ziua in care suma cheltuita este maxima
    '''
    lista_aux = [0]*31
    for el in lista_cheltuieli:
        lista_aux[get_zi(el)] += get_suma(el)
    return get_zi(max(lista_cheltuieli))



def raport_anumita_suma(lista_cheltuieli, suma):
    '''
    Tipareste o lista noua cu cheltuielile ce au o anumita suma
    :param lista_cheltuieli: lista de cheltuieli (list)
    :param suma: suma (float)
    :return: o lista cu cheltuieli ce au suma data de utilizator
    '''
    lista_noua = []
    for el in lista_cheltuieli:
        if get_suma(el) == suma:
            lista_noua.append(el)
    return lista_noua

# Filtrare

def filtrare_cheltuiala_tip(lista_cheltuieli, tip):
    '''
    Filtreaza lista si face o noua lista fara elementele de tipul specificat de utilizator
    :param lista_cheltuieli: lista de cheltuieli (list)
    :param tip: tipul de cheltuiala ce va fi eliminata (string)
    :return: returneaza o noua lista cu toate cheltuielile inafara de un anumit tip specificat de utilizator
    '''
    lista_noua = []
    for el in lista_cheltuieli:
        if get_tip(el) != tip:
            lista_noua.append(el)
    return lista_noua

def filtrare_cheltuieli_suma(lista_cheltuieli, suma):
    '''
    Filtreaza si returneaza o lista auxiliara cu lista de cheltuieli mai mare decat suma data
    :param lista_cheltuieli: lista de cheltuieli (list)
    :param suma: suma de la care se adauge cheltuiala in lista
    :return: returneaza o lista auxiliara cu cheltuielile mai mare decat suma data
    '''
    lista_aux = []
    for el in lista_cheltuieli:
        if get_suma(el) > suma:
            lista_aux.append(el)
    return lista_aux
