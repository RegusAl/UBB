"""

Se cere dezvoltarea unei aplicatii care gestioneaza informatii despre seriale TV.
Fiecare serial este caracterizat de un titlu (string), an aparitie (int)
si un numar de episoade difuzate (int).

Aplicatia are interfata de tip consola, si ofera urmatoarele functionalitati:

1. Adaugare serial (titlu, an aparitie, nr_episoade)
2. Se elimina din lista serialele dintr-o perioada data (an inceput, an sfarsit se dau de la tastatura)
3. Afiseaza numarul de seriale care au mai multe episoade decat un numar citit de la tastatura.
4. Undo ultima operatie
5. Inchiderea aplicatiei

Se va adauga o optiune pentru printarea listei curente (sau se va printa dupa fiecare operatie).
Se cere folosirea procesului de dezvoltare incrementala
bazata pe functionalitati si dezvoltarea dirijata de teste.
"""

# functii care tin lucrul cu entitatea serial si cu lista
from termcolor import colored


def generate_shows():
    # 2000-2010: 4
    # 2018-2020: 2

    # 300: 1
    # 150: 5
    # 80: 7
    # 5: lungimea listei

    return [{'titlu': "The Walking Dead", 'an_aparitie': 2010, 'eps': 177},
            {'titlu': "Outlander", 'an_aparitie': 2014, 'eps': 87},
            {'titlu': "Supernatural", 'an_aparitie': 2005, 'eps': 327},
            {'titlu': "The Witcher", 'an_aparitie': 2019, 'eps': 8},
            {'titlu': "Ozark", 'an_aparitie': 2017, 'eps': 30},
            {'titlu': "Brooklyn Nine-Nine", 'an_aparitie': 2013, 'eps': 153},
            {'titlu': "New Amsterdam", 'an_aparitie': 2018, 'eps': 61},
            {'titlu': "The Good Place", 'an_aparitie': 2016, 'eps': 50},
            {'titlu': "Burn Notice", 'an_aparitie': 2007, 'eps': 111},
            {'titlu': "Strike Back", 'an_aparitie': 2010, 'eps': 77},
            {'titlu': "Stargate SG-1", 'an_aparitie': 1997, 'eps': 214},
            {'titlu': "Charmed", 'an_aparitie': 1998, 'eps': 179},
            {'titlu': "Squid Game", 'an_aparitie': 2021, 'eps': 9}
            ]


def get_titlu(show):
    return show['titlu']


def get_an_aparitie(show):
    return show['an_aparitie']


def get_episoade(show):
    return show['eps']


def create_tv_show(titlu, an_aparitie, eps):
    """
    Creeaza un serial
    :param titlu: titlul serialului
    :type titlu: string
    :param an_aparitie: anul de aparitie al serialului
    :type an_aparitie: int
    :param eps: numarul de episoade difuzate
    :type eps: int
    :return: serialul creat
    :rtype: dict (chei: titlu, an_aparitie, eps)
    """
    return {'titlu': titlu, 'an_aparitie': an_aparitie, 'eps': eps}


def add_show_to_list(show_list, show):
    """
    Adauga un serial la lista data
    :param show_list: lista de seriale
    :type show_list: list
    :param show: serialul care trebuie adaugat
    :type show: dict
    :return: -; lista de seriale se modifica prin adaugarea serialului dat
    :rtype: -;
    """
    show_list.append(show)


def remove_shows_from_list(show_list, an_start, an_end):
    """
    Elimina din lista serialele cu an_aparitie intre anii dati
    :param show_list: lista de seriale
    :type show_list: list (of dicts)
    :param an_start: anul de inceput
    :type an_start: int
    :param an_end: anul de sfarsit
    :type an_end: int
    :return: lista cu serialele care au anul de aparitie <an_start, >an_end
    :rtype: list (of dicts)
    """
    new_list = [show for show in show_list if get_an_aparitie(show) < an_start or get_an_aparitie(show) > an_end]
    return new_list


def get_no_shows_more_episodes(show_list, no_eps):
    """
    Gaseste numarul de seriale cu numar de episoade mai mare decat numarul dat
    :param show_list: lista de seriale
    :type show_list: list (of dicts)
    :param no_eps: numarul de episoade dat
    :type no_eps: int
    :return: numarul de seriale cu numar episoade mai mare decat numarul dat
    :rtype: int
    """
    count_no_shows = 0
    for show in show_list:
        if get_episoade(show) > no_eps:
            count_no_shows += 1
    return count_no_shows


# partea de interfata cu utilizatorul

def print_menu():
    print("1. Adaugare serial (titlu, an aparitie, nr_episoade)")
    print("2. Se elimina din lista serialele dintr-o perioada data (an inceput, an sfarsit se dau de la tastatura)")
    print("3. Afiseaza numarul de seriale care au mai multe episoade decat un numar citit de la tastatura. ")
    print("4. Undo ultima operatie")
    print("P. Afisarea listei curente")
    print("5. Inchiderea aplicatiei")


def print_show_list(show_list):
    for i, show in enumerate(show_list):
        print(i, 'Titlu:', colored(get_titlu(show), 'blue'), '- An aparitie:', colored(get_an_aparitie(show), 'blue'),
              '- Episoade:', colored(get_episoade(show), 'blue'))


def add_show_ui(show_list):
    titlu = input("Titlul serialului:")
    an_aparitie = int(input("Anul aparitiei:"))
    eps = int(input("Numar de episoade difuzate:"))

    show = create_tv_show(titlu, an_aparitie, eps)
    add_show_to_list(show_list, show)


def delete_shows_ui(show_list):
    an_start = int(input('Anul de start:'))
    an_end = int(input('Anul de sfarsit'))

    show_list = remove_shows_from_list(show_list, an_start, an_end)
    return show_list


def filter_shows_ui(show_list):
    eps = int(input('Numar de episoade:'))
    how_many_shows = get_no_shows_more_episodes(show_list, eps)
    print('Numarul de show-uri cu mai multe episoade:', how_many_shows)


def start():
    crt_show_list = generate_shows()
    finished = False
    while not finished:
        print_menu()
        option = input("Optiunea dumneavoastra este:")
        if option == '1':
            add_show_ui(crt_show_list)
            print(colored("Serialul s-a adaugat cu succes.", 'green'))
        elif option == '2':
            crt_show_list = delete_shows_ui(crt_show_list)
            print(colored("Serialele s-au sters cu succes.", 'green'))
        elif option == '3':
            filter_shows_ui(crt_show_list)
        elif option.lower() == 'p':
            print_show_list(crt_show_list)

        elif option == '5':
            finished = True
        else:
            print(colored("Optiunea introdusa este invalida.", 'red'))


start()


# teste
def test_create_show():
    show1 = create_tv_show('Supernatural', 2005, 327)
    assert (type(show1) == dict)
    assert (get_titlu(show1) == 'Supernatural')
    assert (get_an_aparitie(show1) == 2005)
    assert (get_episoade(show1) == 327)

    # cand se vorbeste de date introduse invalid
    # vor trebui teste si pentru acele cazuri cu
    # exceptii


def test_add_show_to_list():
    test_list = []
    show = create_tv_show('See', 2019, 12)
    add_show_to_list(test_list, show)

    assert (len(test_list) == 1)
    assert (get_titlu(test_list[0]) == 'See')
    assert (get_an_aparitie(test_list[0]) == 2019)
    assert (get_episoade(test_list[0]) == 12)

    show = create_tv_show('Suits', 2011, 134)
    add_show_to_list(test_list, show)

    assert (len(test_list) == 2)
    assert (get_titlu(test_list[1]) == 'Suits')
    assert (get_an_aparitie(test_list[1]) == 2011)
    assert (get_episoade(test_list[1]) == 134)


def test_remove_show_from_list():
    test_list = generate_shows()
    initial_length = len(test_list)

    test_list = remove_shows_from_list(test_list, 2000, 2010)
    assert (len(test_list) == initial_length - 4)
    assert (len([show for show in test_list if get_an_aparitie(show) >= 2000 and get_an_aparitie(show) <= 2010]) == 0)

    initial_length2 = len(test_list)
    test_list = remove_shows_from_list(test_list, 2018, 2020)
    assert (len(test_list) == initial_length2 - 2)
    assert (len([show for show in test_list if get_an_aparitie(show) >= 2018 and get_an_aparitie(show) <= 2020]) == 0)

    test_list = remove_shows_from_list(test_list, 1990, 2025)
    assert (len(test_list) == 0)


def test_no_shows():
    test_list = generate_shows()

    # 300: 1
    # 150: 5
    # 80: 7
    # 5: lungimea listei

    more_than_300 = get_no_shows_more_episodes(test_list, 300)
    assert (more_than_300 == 1)

    more_than_150 = get_no_shows_more_episodes(test_list, 150)
    assert (more_than_150 == 5)

    more_than_80 = get_no_shows_more_episodes(test_list, 80)
    assert (more_than_80 == 7)

    more_than_5 = get_no_shows_more_episodes(test_list, 5)
    assert (more_than_5 == len(test_list))


test_create_show()
test_add_show_to_list()
test_remove_show_from_list()
test_no_shows()
