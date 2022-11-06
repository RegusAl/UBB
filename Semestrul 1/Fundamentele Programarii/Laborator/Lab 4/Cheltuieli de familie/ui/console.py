from domain.cheltuiala import test_cheltuiala_valida, creeaza_cheltuiala, test_zi_valida, test_suma_valida, \
    test_tip_valid, global_list, test_zile, test_undo
from utils.operations import adauga_cheltuiala, actualizare_cheltuiala, stergere_cheltuiala_zi, \
    stergere_cheltuiala_interval, stergere_cheltuiala_tip, cautare_cheltuieli_suma, cautare_cheltuieli_zi_suma, \
    cautare_cheltuieli_tip, raport_suma_din_tip, filtrare_cheltuiala_tip, filtrare_cheltuieli_suma, raport_anumita_suma, \
    raport_suma_max, raport_cheltuieli_sortate_tip


# Meniul principal
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

## Functii UI

def afiseaza_cheltuieli_ui(lista):
    print("Lista cu cheltuieli este: \n")
    for el in lista:
        print("Ziua:", el[0], "Suma:", el[1], "Tipul:", el[2])
    print("\n")

### Adauga cheltuiala - UI
def adauga_cheltuieli_ui(lista_cheltuieli):
    try:
        ziua = int(input("Ziua:"))
        suma = float(input("Suma:"))
        tip = input("Tipul cheltuielii:")
        cheltuiala = creeaza_cheltuiala(ziua, suma, tip)
        test_zi_valida(ziua)
        test_suma_valida(suma)
        test_tip_valid(tip)
        test_cheltuiala_valida(cheltuiala)
        adauga_cheltuiala(lista_cheltuieli, cheltuiala)
    except ValueError:
        print("!!!Cheltuiala nu este valida!!!")
        return
    except AssertionError:
        print("!!!Cheltuiala nu este valida!!!")
        return
    except TypeError:
        print("!!!Cheltuiala nu este valida!!!")
        return

def actualizare_cheltuiala_ui(lista_cheltuieli):
    print("Alegeti ce cheltuiala vreti sa actualizati")
    try:
        ziua = int(input("Ziua:"))
        suma = float(input("Suma:"))
        tip = input(("Tipul cheltuielii:"))
        print("Inserati schimbarile cheltuielii")
        ziua_noua = int(input("Ziua:"))
        suma_noua = float(input("Suma:"))
        tip_noua = input(("Tipul cheltuielii:"))
        cheltuiala = creeaza_cheltuiala(ziua, suma, tip)
        test_cheltuiala_valida(cheltuiala)
        test_zi_valida(ziua_noua)
        test_suma_valida(suma_noua)
        test_tip_valid(tip_noua)
        cheltuiala_noua = actualizare_cheltuiala(lista_cheltuieli, ziua_noua, suma_noua, tip_noua, cheltuiala)
        if cheltuiala_noua == {}:
            print("Nu puteti actualiza o cheltuiala daca aceasta nu exista!\n")
        else:
            adauga_cheltuiala(lista_cheltuieli, cheltuiala_noua)
    except ValueError:
        print("!!!Nu se poate actualiza cheltuiala deoarece operatia nu este valida!!!")
        return
    except AssertionError:
        print("!!!Nu se poate actualiza cheltuiala deoarece operatia nu este valida!!!")
        return
    except TypeError:
        print("!!!Nu se poate actualiza cheltuiala deoarece operatia nu este valida!!!")
        return

### Stergere -UI

def stergere_cheltuiala_zi_ui(lista_cheltuieli):
    try:
        ziua = int(input("Ziua in care se sterg toate cheltuielile:"))
        test_zi_valida(ziua)
        stergere_cheltuiala_zi(lista_cheltuieli, ziua)
    except ValueError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return
    except AssertionError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return
    except TypeError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return

def stergere_cheltuiala_interval_ui(lista_cheltuieli):
    try:
        zi_inceput = int(input("Ziua de inceput in care se sterg cheltuielile:"))
        test_zi_valida(zi_inceput)
        zi_sfarsit = int(input("Ziua de sfarsit:"))
        test_zi_valida(zi_sfarsit)
        test_zile(zi_inceput, zi_sfarsit)
        stergere_cheltuiala_interval(lista_cheltuieli, zi_inceput, zi_sfarsit)
    except ValueError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return
    except AssertionError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return
    except TypeError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return

def stergere_cheltuiala_tip_ui(lista_cheltuieli):
    try:
        tipul = input("Tipul de cheltuiala care va fi sters:")
        test_tip_valid(tipul)
        stergere_cheltuiala_tip(lista_cheltuieli, tipul)
    except ValueError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return
    except AssertionError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return
    except TypeError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return

### Cautare - UI

def cautare_cheltuieli_suma_ui(lista_cheltuieli):
    try:
        suma = float(input("Alege suma pentru care sa se afiseze cheltuielile mai mari decat suma data:"))
        test_suma_valida(suma)
        afiseaza_cheltuieli_ui(cautare_cheltuieli_suma(lista_cheltuieli, suma))
        print("\n")
    except ValueError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return
    except AssertionError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return
    except TypeError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return


def cautare_cheltuieli_zi_suma_ui(lista_cheltuieli):
    try:
        zi = int(input("Ziua pana la care sa se afiseze cheltuielile:"))
        test_zi_valida(zi)
        suma = float(input("Suma pana la care sa se afiseze cheltuielile:"))
        test_suma_valida(suma)
        afiseaza_cheltuieli_ui(cautare_cheltuieli_zi_suma(lista_cheltuieli, zi, suma))
        print("\n")
    except ValueError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return
    except AssertionError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return
    except TypeError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return

def cautare_cheltuieli_tip_ui(lista_cheltuieli):
    try:
        tip = input("Tipul pentru care vreti sa vedeti cheltuielile:")
        test_tip_valid(tip)
        afiseaza_cheltuieli_ui(cautare_cheltuieli_tip(lista_cheltuieli, tip))
    except ValueError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return
    except AssertionError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return
    except TypeError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return

### Raport - UI

def raport_suma_din_tip_ui(lista_cheltuieli):
    try:
        tip = input("Tipul pentru care vreti sa aflati suma totala:")
        test_tip_valid(tip)
        print("Suma totala este", raport_suma_din_tip(lista_cheltuieli, tip))
    except ValueError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return
    except AssertionError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return
    except TypeError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return

def raport_suma_max_ui(lista_cheltuieli):
    print("Ziua in care suma cheltuita este maxima este: ", raport_suma_max(lista_cheltuieli))

def raport_anumita_suma_ui(lista_cheltuieli):
    try:
        suma = float(input("Suma pentru care vreti sa vedeti cheltuielile:"))
        test_suma_valida(suma)
        print("Cheltuielile sunt: ")
        afiseaza_cheltuieli_ui(raport_anumita_suma(lista_cheltuieli, suma))
    except ValueError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return
    except AssertionError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return
    except TypeError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return

def raport_cheltuieli_sortate_tip_ui(lista_cheltuieli):
    print("Cheltuielile sortate dupa tip:")
    afiseaza_cheltuieli_ui(raport_cheltuieli_sortate_tip(lista_cheltuieli))

### Filtrare - UI

def filtrare_cheltuiala_tip_ui(lista_cheltuieli):
    try:
        tipul = input("Tipul de cheltuiala care va fi sters:")
        test_tip_valid(tipul)
        afiseaza_cheltuieli_ui((filtrare_cheltuiala_tip(lista_cheltuieli, tipul)))
    except ValueError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return
    except AssertionError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return
    except TypeError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return

def filtrare_cheltuieli_suma_ui(lista_cheltuieli):
    try:
        suma = float(input("Suma de la care se vor afisa cheltuielile:"))
        test_suma_valida(suma)
        afiseaza_cheltuieli_ui((filtrare_cheltuieli_suma(lista_cheltuieli, suma)))
    except ValueError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return
    except AssertionError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return
    except TypeError:
        print("!!!Operatia nu se poate efectua. Inserati valori valide!!!")
        return

## Functii de printere a mini-meniului

def optiune_invalida():
    print("Optiune invalida! Te rugam sa incerci din nou.\n")

def print_adaugare_cheltuiala(list):
    print("1. Adauga o noua cheltuiala (ziua, suma, tipul)")
    print("2. Actualizeaza cheltuiala (ziua, suma, tipul)")
    new_option = input("Optiunea de adaugare este:")
    if new_option == "1":
        adauga_cheltuieli_ui(list)
    elif new_option == "2":
        actualizare_cheltuiala_ui(list)
    else:
        optiune_invalida()

def print_stergere(list):
    print("1. Șterge toate cheltuielile pentru ziua dată")
    print("2. Șterge cheltuielile pentru un interval de timp (se dă ziua de început și sfârșit)")
    print("3. Șterge toate cheltuielile de un anumit tip")
    new_option = input("Optiunea de stergere este:")
    if new_option == "1":
        stergere_cheltuiala_zi_ui(list)
    elif new_option == "2":
        stergere_cheltuiala_interval_ui(list)
    elif new_option == "3":
        stergere_cheltuiala_tip_ui(list)
    else:
        optiune_invalida()

def print_cautari(list):
    print("1. Tipărește toate cheltuielile mai mari decât o sumă dată")
    print("2. Tipărește toate cheltuielile efectuate înainte de o zi dată și mai mici decât o sumă")
    print("3. Tipărește toate cheltuielile de un anumit tip")
    new_option = input("Optiunea de cautare este:")
    if new_option == "1":
        cautare_cheltuieli_suma_ui(list)
    elif new_option == "2":
        cautare_cheltuieli_zi_suma_ui(list)
    elif new_option == "3":
        cautare_cheltuieli_tip_ui(list)
    else:
        optiune_invalida()

def print_rapoarte(list):
    print("1. Tipărește suma totală pentru un anumit tip de cheltuială")
    print("2. Găsește ziua în care suma cheltuită e maximă")
    print("3. Tipărește toate cheltuielile ce au o anumită sumă")
    print("4. Tipărește cheltuielile sortate după tip")
    new_option = input("Optiunea de raport:")
    if new_option == "1":
        raport_suma_din_tip_ui(list)
    elif new_option == "2":
        raport_suma_max_ui(list)
    elif new_option == "3":
        raport_anumita_suma_ui(list)
    elif new_option == "4":
        raport_cheltuieli_sortate_tip_ui(list)
    else:
        optiune_invalida()

def print_filtrare(list):
    print("1. Elimină toate cheltuielile de un anumit tip")
    print("2. Elimină toate cheltuielile mai mici decât o sumă dată")
    new_option = input("Optiunea de filtrare este:")
    if new_option == "1":
        filtrare_cheltuiala_tip_ui(list)
    elif new_option == "2":
        filtrare_cheltuieli_suma_ui(list)
    else:
        optiune_invalida()

def start():
    crt_list = global_list()
    lista_undo = []
    #lista_undo = global_list()
    finished = False
    while not finished:
        print_menu()
        option = input("Optiunea dumneavoastra este:")
        # Adauga cheltuiala
        if option == "1":
            lista_undo.append(crt_list.copy())
            print_adaugare_cheltuiala(crt_list)
        # Stergere cheltuiala
        elif option == "2":
            lista_undo.append(crt_list.copy())
            print_stergere(crt_list)
        # Cautari
        elif option == "3":
            print_cautari(crt_list)
        # Rapoarte
        elif option == "4":
            print_rapoarte(crt_list)
        # Filtrare
        elif option == "5":
            print_filtrare(crt_list)
        # Undo
        elif option == "6":
            try:
                test_undo(lista_undo)
                crt_list = lista_undo[-1].copy()
                del lista_undo[-1]
            except ValueError:
                print("!!!Nu se poate face UNDO!!!")
            except AssertionError:
                print("!!!Nu se poate face UNDO!!!")
            except TypeError:
                print("!!!Nu se poate face UNDO!!!")
        # Afisare lista
        elif option == "7":
            afiseaza_cheltuieli_ui(crt_list)
        # Exit
        elif option == "8":
            finished = True
        else:
            optiune_invalida()
