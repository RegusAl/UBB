'''
Scrieți o aplicație care gestionează cheltuielile de familie efectuate într-o lună.
Pentru o cheltuială se vor retine ziua (din luna), suma, tipul cheltuielii (5 categorii:
mâncare, întreținere, îmbrăcăminte, telefon, altele)

Aplicatia are interfata de tip consola, si ofera urmatoarele functionalitati:

1. Adaugă cheltuiala:
    - Adaugă o noua cheltuiala (se specifica ziua, suma, tipul)
    - Actualizează cheltuiala (se specifica ziua, suma, tipul)
2. Stergere:
    - Șterge toate cheltuielile pentru ziua dată
    - Șterge cheltuielile pentru un interval de timp (se dă ziua de început și
    sfârșit, se șterg toate cheltuielile pentru perioada dată)
    - Șterge toate cheltuielile de un anumit tip
3. Căutări:
    - Tipărește toate cheltuielile mai mari decât o sumă dată
    - Tipărește toate cheltuielile efectuate înainte de o zi dată și mai mici
    decât o sumă (se dă suma și ziua, se tipăresc toate cheltuielile mai
    mici ca suma dată și efectuate înainte de ziua specificată)
    - Tipărește toate cheltuielile de un anumit tip
4. Rapoarte:
    - Tipărește suma totală pentru un anumit tip de cheltuială
    - Găsește ziua în care suma cheltuită e maximă
    - Tipărește toate cheltuielile ce au o anumită sumă
    - Tipărește cheltuielile sortate după tip
5. Filtrare:
    - Elimină toate cheltuielile de un anumit tip
    - Elimină toate cheltuielile mai mici decât o sumă dată
6. Undo:
    - Reface ultima operație (lista de cheltuieli revine ce exista înainte de
ultima operație care a modificat lista)
'''

def global_list():
    return [{"zi":  1, "suma": 25, "tip": "mancare"},
            {"zi":  4, "suma": 45, "tip": "intretinere"},
            {"zi":  7, "suma": 29.16, "tip": "telefon"},
            {"zi":  12, "suma": 99.78, "tip": "imbracaminte"},
            {"zi":  15, "suma": 100.78, "tip": "mancare"},
            {"zi":  20, "suma": 13.90, "tip": "altele"}
            ]

# teste

# testare pentru cazurile cu exceptie la adaugare cheltuiala
def test_cheltuiala_valida(cheltuiala):
    tip = ["mancare", "intretinere", "imbracaminte", "telefon", "altele"]
    assert (type(cheltuiala) == dict)
    assert (type(get_suma(cheltuiala)) == float)
    assert (type(get_zi(cheltuiala)) == int)
    assert (get_zi(cheltuiala)>0 and get_zi(cheltuiala)<=31)
    assert (get_tip(cheltuiala) in tip)

# testare pentru cazurile cu exceptie la stergere cheltuiala
def test_zi_valida(zi):
    assert (zi > 0 and zi <= 31)
    assert (type(zi)==int)

# testare pentru cazurile de exceptie la suma
def test_suma_valida(suma):
    assert (suma > 0)
    assert (type(suma)==float)

# testare pentru cazurile cu exceptie la tipul de cheltuiala
def test_tip_valid(tip):
    tipuri_cheltuieli = ["mancare", "intretinere", "imbracaminte", "telefon", "altele"]
    assert(tip in tipuri_cheltuieli)

# functii

def get_zi(cheltuiala):
    return cheltuiala['zi']

def get_suma(cheltuiala):
    return cheltuiala['suma']

def get_tip(cheltuiala):
    return cheltuiala['tip']

def creeaza_cheltuiala(zi, suma, tip):
    '''
    Creeaza o cheltuiala
    :param zi: int
    :param suma: float
    :param tip: string
    :return: cheltuiala
    '''
    return {"zi": zi, "suma": suma, "tip": tip}

# Adauga cheltuiala

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
        if lista_cheltuieli[i]['zi'] == ziua:
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
        if lista_cheltuieli[i]['zi'] >= zi_inceput and lista_cheltuieli[i]['zi'] <= zi_sfarsit:
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
        if lista_cheltuieli[i]['tip'] == tipul:
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
    for el in lista_cheltuieli:
        if el["suma"] >= suma:
            print(el)

def cautare_cheltuieli_zi_suma(lista_cheltuieli, zi, suma):
    '''
    Cauta si tipareste cheltuielile efectuate inainte de o zi data si mai mici decat o suma
    :param lista_cheltuieli: lista de cheltuieli (list)
    :param zi: ziua pana la care se tiparesc cheltuielile (int)
    :param suma: suma pana la care se tiparesc cheltuielile (float)
    :return: Afiseaza cheltuielile
    '''
    for el in lista_cheltuieli:
        if (zi < el["zi"]) and (suma < el["suma"]):
            print(el)
    print("\n")

def cautare_cheltuieli_tip(lista_cheltuieli, tip):
    '''
    Tipareste toate cheltuielile de un anumit tip
    :param lista_cheltuieli: lista de cheltuieli (list)
    :param tip: tipul de cheltuiala (string)
    :return: Afiseaza cheltuielile de un anumit tip
    '''
    for el in lista_cheltuieli:
        if el["tip"] == tip:
            print(el)

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
        if el["tip"] == tip:
            suma += el["suma"]
    return suma

# Filtrare

# interfata cu utilizatorul

## Meniu

def print_menu():
    print("MENIU")
    print("\n")
    print("1. Adaugare cheltuiala (ziua, suma, tipul: mâncare, întreținere, îmbrăcăminte, telefon, altele)")
    print("2. Stergere")
    print("3. Cautare")
    print("4. Rapoarte")
    print("5. Filtrare")
    print("6. Undo")
    print("7. Lista cu cheltuieli")
    print("8. Exit")
    print("\n")

def print_adaugare_cheltuiala():
    print("1. Adauga o noua cheltuiala (ziua, suma, tipul)")
    print("2. Actualizeaza cheltuiala (ziua, suma, tipul)")

def print_stergere():
    print("1. Șterge toate cheltuielile pentru ziua dată")
    print("2. Șterge cheltuielile pentru un interval de timp (se dă ziua de început și sfârșit)")
    print("3. Șterge toate cheltuielile de un anumit tip")

def print_cautari():
    print("1. Tipărește toate cheltuielile mai mari decât o sumă dată")
    print("2. Tipărește toate cheltuielile efectuate înainte de o zi dată și mai mici decât o sumă")
    print("3. Tipărește toate cheltuielile de un anumit tip")

def print_rapoarte():
    print("1. Tipărește suma totală pentru un anumit tip de cheltuială")
    print("2. Găsește ziua în care suma cheltuită e maximă")
    print("3. Tipărește toate cheltuielile ce au o anumită sumă")
    print("4. Tipărește cheltuielile sortate după tip")

def print_filtrare():
    print("1. Elimină toate cheltuielile de un anumit tip")
    print("2. Elimină toate cheltuielile mai mici decât o sumă dată")

## Functii UI

def adauga_cheltuieli_ui(lista_cheltuieli):
    ziua = int(input("Ziua:"))
    suma = float(input("Suma:"))
    tip = input(("Tipul cheltuielii:"))

    cheltuiala = creeaza_cheltuiala(ziua, suma, tip)
    test_cheltuiala_valida(cheltuiala)
    adauga_cheltuiala(lista_cheltuieli, cheltuiala)

def stergere_cheltuiala_zi_ui(lista_cheltuieli):
    ziua = int(input("Ziua in care se sterg toate cheltuielile:"))
    test_zi_valida(ziua)
    stergere_cheltuiala_zi(lista_cheltuieli, ziua)

def stergere_cheltuiala_interval_ui(lista_cheltuieli):
    zi_inceput = int(input("Ziua de inceput in care se sterg cheltuielile:"))
    test_zi_valida(zi_inceput)
    zi_sfarsit = int(input("Ziua de sfarsit:"))
    test_zi_valida(zi_sfarsit)
    stergere_cheltuiala_interval(lista_cheltuieli, zi_inceput, zi_sfarsit)

def stergere_cheltuiala_tip_ui(lista_cheltuieli):
    tipul = input("Tipul de cheltuiala care va fi sters:")
    test_tip_valid(tipul)
    stergere_cheltuiala_tip(lista_cheltuieli, tipul)

def cautare_cheltuieli_suma_ui(lista_cheltuieli):
    suma = float(input("Alege suma pentru care sa se afiseze cheltuielile mai mari decat suma data:"))
    test_suma_valida(suma)
    cautare_cheltuieli_suma(lista_cheltuieli, suma)

def cautare_cheltuieli_zi_suma_ui(lista_cheltuieli):
    zi = int(input("Ziua pana la care sa se afiseze cheltuielile:"))
    test_zi_valida(zi)
    suma = float(input("Suma pana la care sa se afiseze cheltuielile:"))
    test_suma_valida(suma)
    cautare_cheltuieli_zi_suma(lista_cheltuieli, zi, suma)

def cautare_cheltuieli_tip_ui(lista_cheltuieli):
    tip = input("Tipul pentru care vreti sa vedeti cheltuielile:")
    test_tip_valid(tip)
    cautare_cheltuieli_tip(lista_cheltuieli, tip)

def raport_suma_din_tip_ui(lista_cheltuieli):
    tip = input("Tipul pentru care vreti sa aflati suma totala:")
    test_tip_valid(tip)
    print("Suma totala este", raport_suma_din_tip(lista_cheltuieli, tip))

def filtrare_cheltuiala_tip_ui(lista_cheltuieli):
    tipul = input("Tipul de cheltuiala care va fi sters:")
    test_tip_valid(tipul)
    stergere_cheltuiala_tip(lista_cheltuieli, tipul)


def afiseaza_cheltuieli_ui(lista):
    print("Lista cu cheltuieli este: \n")
    print(lista)

# Start



def start():
    crt_list = global_list()
    finished = False
    while not finished:
        print_menu()
        option = input("Optiunea dumneavoastra este:")
        # Adauga cheltuiala
        if option == "1":
            adauga_cheltuieli_ui(crt_list)
        # Stergere cheltuiala
        elif option == "2":
            print_stergere()
            new_option = input("Optiunea de stergere este:")
            if new_option == "1":
                stergere_cheltuiala_zi_ui(crt_list)
            elif new_option == "2":
                stergere_cheltuiala_interval_ui(crt_list)
            elif new_option == "3":
                stergere_cheltuiala_tip_ui(crt_list)
        # Cautari
        elif option == "3":
            print_cautari()
            new_option = input("Optiunea de cautare este:")
            if new_option == "1":
                cautare_cheltuieli_suma_ui(crt_list)
            elif new_option == "2":
                cautare_cheltuieli_zi_suma_ui(crt_list)
            elif new_option == "3":
                cautare_cheltuieli_tip_ui(crt_list)
        # Rapoarte
        elif option == "4":
            print_rapoarte()
            new_option = input("Optiunea de raport:")
            if new_option == "1":
                raport_suma_din_tip_ui(crt_list)
        # Filtrare
        elif option == "5":
            print_filtrare()
            new_option = input("Optiunea de filtrare este:")
            if new_option == "1":
                filtrare_cheltuiala_tip_ui(crt_list)
        #Undo
        elif option == "6":
            print("undo")
        # Afisare lista
        elif option == "7":
            afiseaza_cheltuieli_ui(crt_list)
        # Exit
        elif option == "8":
            finished = True
        else:
            print("Optiunea nu este valida!")

start()


# teste