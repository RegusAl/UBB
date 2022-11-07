from termcolor import colored

from domain.show import get_titlu, get_episoade, get_an_aparitie, create_tv_show
from domain.show_manager import add_show_to_manager, delete_show_from_manager, get_no_shows_more_episodes, undo, \
    setup_show_manager, get_show_list


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


def add_show_ui(show_manager):
    titlu = input("Titlul serialului:")
    try:
        an_aparitie = int(input("Anul aparitiei:"))
        eps = int(input("Numar de episoade difuzate:"))
    except ValueError:
        print(colored('Anul aparitiei si nr. episoade trebuie sa fie un numar.', 'red'))
        return

    #daca in urma validarilor implementate se arunca alta exceptie
    #decat ValueError puteam continua, ex. except ValidationException...

    try:
        add_show_to_manager(show_manager, titlu, an_aparitie, eps)
        print(colored("Serialul s-a adaugat cu succes.", 'green'))
    except ValueError as ve:
        print(colored(str(ve),'red'))





def delete_shows_ui(show_manager):
    try:
        an_start = int(input('Anul de start:'))
        an_end = int(input('Anul de sfarsit'))
        delete_show_from_manager(show_manager, an_start, an_end)
    except ValueError:
        print(colored('Introduceti valori numerice pentru ani.', 'red'))


def filter_shows_ui(show_list):
    # check for non-integer number and print message
    try:
        eps = int(input('Numar de episoade:'))
        how_many_shows = get_no_shows_more_episodes(show_list, eps)
        print('Numarul de show-uri cu mai multe episoade:', how_many_shows)
    except ValueError:
        print(colored('Numarul de episoade trebuie sa fie numar natural.','red'))


def undo_ui(show_manager):
    try:
        undo(show_manager)
        print(colored("Undo realizat cu succes.", 'green'))
    except ValueError as ve:
        print(colored(ve, 'red'))


def start():
    # [crt_show_list, undo_list]
    show_manager = setup_show_manager(True)
    finished = False
    while not finished:
        print_menu()
        option = input("Optiunea dumneavoastra este:")
        if option == '1':
            add_show_ui(show_manager)
        elif option == '2':
            delete_shows_ui(show_manager)
        elif option == '3':
            filter_shows_ui(get_show_list(show_manager))
        elif option == '4':
            undo_ui(show_manager)
        elif option.lower() == 'p':
            print_show_list(get_show_list(show_manager))

        elif option == '5':
            finished = True
        else:
            print(colored("Optiunea introdusa este invalida.", 'red'))