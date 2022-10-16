"""
Scrieti o aplicatie care are interfata utilizator tip consola cu meniu. Aplicatia ofera urmatoarele functionalitati:

1. Citeste de la tastatura o lista de nume de seriale TV, sub forma NumeSerial_an.
2. Afiseaza toate serialele al caror nume incepe cu litera "A".
3. Afiseaza toate serialele dintr-un an dat.
4. Afiseaza diferenta in ani intre cel mai nou si cel mai vechi serial.
5. Iesire din aplicatie

"""
import math

#from termcolor import colored


def print_menu():
    print("1. Citeste de la tastatura o lista de nume de seriale TV, sub forma NumeSerial_an.")
    print("10. Adauga un serial la lista.")
    print("2. Afiseaza toate serialele al caror nume incepe cu litera \"A\". ")
    print("3. Afiseaza toate serialele dintr-un an dat. ")
    print("4. Afiseaza diferenta (in ani) intre cel mai nou si cel mai vechi serial.")
    print("5. Iesire din aplicatie")


def read_list():
    # Lista sa fie data sub forma: Serial1_An1, Serial2_An2, Serial3_An3
    # list_as_string = input("Introduceti lista sub formatul cerut: ")
    # the_list = list_as_string.split()
    # return the_list
    show_list = []
    n = int(input("Cate seriale se citesc?"))
    for i in range(n):
        show = input("Introduceti serial:")
        show_list.append(show)
    return show_list

def add_to_list(lst, serial):
    lst.append(serial)



def print_list(message, lst):
    print(message, colored(lst, 'green'))


def populate_list(the_list):
    """
    Populeaza lista data cu niste seriale predefinite
    :param the_list: lista data
    :type the_list: list
    :return: -; lista data se modifica prin adaugarea serialelor date
    :rtype:
    """
    the_list.append("TheWitcher_2019")
    the_list.append("PrisonBreak_2015")
    the_list.append("TheAmericans_2013")
    the_list.append("Brooklyn99_2013")
    the_list.append("Mindunter_2017")
    the_list.append("BattlestarGalactica_2004")
    the_list.append("TheCrown_2016")
    the_list.append("Andromeda_2000")


def get_all_starting_with(the_list, letter):
    """
    Gaseste toate serialele dintr-o lista data al caror nume incepe cu litera data
    :param the_list: lista cu serialele in care se cauta
    :type the_list: list
    :param letter: litera data
    :type letter: str
    :return: serialele care incep cu litera data
    :rtype: list
    """
    elems = []
    # for el in the list (el = Serial1_An1, Serial2_An2)
    # for i in range(len(the_list)) - i = 0,1,2,..., len(the_list)-1, the_list[i]: Serial1_An1...
    for el in the_list:
        # if el.startswith(letter)
        if el[0] == letter:
            elems.append(el)
    return elems


def get_all_from_year(the_list, year):
    """
    Gaseste toate serialele cu anul dat din lista
    :param the_list: lista cu seriale data
    :type the_list: list
    :param year: anul dat
    :type year: str
    :return: lista cu seriale din anul dat
    :rtype: list
    """
    elems = []
    for el in the_list:
        # nume serial: NumeSerial_an
        # [NumeSerial, an]
        el_year = el.split("_")[1]
        # if el.find(year)>0:
        if el_year == year:
            elems.append(el)
    return elems


def show_difference(the_list):
    """
    Calculeaza diferenta in ani dintre cel mai nou si cel mai vechi serial
    :param the_list: lista cu seriale data
    :type the_list: list
    :return: diferenta in ani dintre cel mai nou si cel mai vechi serial
    :rtype: int
    """
    min = math.inf
    max = 0

    for el in the_list:
        el_year = int(el.split("_")[1])
        if el_year > max:
            max = el_year
        elif el_year < min:
            min = el_year

    return max - min


def start():
    current_list = []
    populate_list(current_list)
    while True:
        print_menu()
        print_list('Lista curenta este', current_list)
        option = int(input("Optiunea dumneavoastra este:"))
        if option == 1:
            current_list = read_list()
        if option == 10:
            new_show = input("Serialul de adaugat:")
            add_to_list(current_list, new_show)
        if option == 2:
            current_letter = "A"
            print_list("Lista ceruta este:", get_all_starting_with(current_list, current_letter))
        if option == 3:
            current_year = input("Anul este:")
            #if we convert current_year to int here, we need to also do it for the elements in the list
            print_list("Lista ceruta este:", get_all_from_year(current_list, current_year))
        if option == 4:
            print("Diferenta dintre cel mai nou si cel mai vechi show este:", show_difference(current_list))
        elif option == 5:
            return


start()
