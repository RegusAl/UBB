from termcolor import colored


class Console:
    def __init__(self, srv):
        """
        Initializeaza consola
        :type srv: ShowService
        """
        self.__srv = srv

    def __print_shows(self, show_list):
        """
        Afiseaza o lista de seriale

        """

        if len(show_list) == 0:
            print('Nu exista seriale in lista.')
        else:
            print('Lista de seriale este:')
            for show in show_list:
                # print(show)
                print('ID: ', colored(show.getId(), 'cyan'),
                      ' - Titlu serial: ', colored(show.getTitle(), 'cyan'), ' - An aparitie: ',
                      colored(str(show.getAnAparitie()),
                              'cyan'), ' - Nr. episoade: ', colored(str(
                        show.getEpisoade()), 'cyan'))

    def __add_show(self):
        """
        Adauga un serial cu datele citite de la tastatura
        """
        id = input('Identificator serial:')
        titlu = input("Titlul serialului:")
        try:
            an_aparitie = int(input("Anul aparitiei:"))
            eps = int(input("Numar de episoade difuzate:"))
        except ValueError:
            print(colored('Anul aparitiei si nr. episoade trebuie sa fie un numar.', 'red'))
            return

        try:
            added_show = self.__srv.add_show(id, titlu, an_aparitie, eps)
            print('Serialul ' + added_show.getTitle() + ' (' + str(
                added_show.getAnAparitie()) + ') a fost adaugat cu succes.')
        except ValueError as ve:
            print(colored(str(ve), 'red'))

    def __delete_show(self):
        id = input('Identificatorul serialului de sters:')
        try:
            deleted_show = self.__srv.delete_show(id)
            print('Serialul ' + deleted_show.getTitle() + ' (' + str(
                deleted_show.getAnAparitie()) + ') a fost sters cu succes (ID=' + str(deleted_show.getId()) + ').')
        except ValueError as ve:
            print(colored(str(ve), 'red'))

    def __update_show(self):
        id = input('Identificator serial:')
        titlu = input("Titlul serialului:")
        try:
            an_aparitie = int(input("Anul aparitiei:"))
            eps = int(input("Numar de episoade difuzate:"))
        except ValueError:
            print(colored('Anul aparitiei si nr. episoade trebuie sa fie un numar.', 'red'))
            return

        try:
            modified_show = self.__srv.update_show(id, titlu, an_aparitie, eps)
            print('Serialul ' + modified_show.getTitle() + ' (' + str(
                modified_show.getAnAparitie()) + ') a fost modificat cu succes.')
        except ValueError as ve:
            print(colored(str(ve), 'red'))

    def __delete_by_years(self):
        """
        Sterge serialele dintr-o perioada data
        """
        try:
            an_start = int(input("Anul de inceput:"))
            an_end = int(input("Anul de sfarsit:"))
        except ValueError:
            print(colored('Anii trebuie sa fie numere.', 'red'))
            return

        how_many_deleted = self.__srv.delete_by_years(an_start, an_end)
        print('S-au sters cu succes', colored(how_many_deleted, 'cyan'), ' seriale din perioada: ', an_start, '-',
              an_end, '.')

    def __filter_by_no_eps(self):
        """
        Afiseaza serialele care un numar mai mare de episoade decat cel dat
        """
        try:
            no_eps = int(input("Numarul de episoade dupa care se filtreaza:"))
        except ValueError:
            print(colored('Numarul de episoade trebuie sa fie un nr. natural.', 'red'))
            return

        filtered_list = self.__srv.filter_by_no_episodes(no_eps)
        self.__print_shows(filtered_list)

    def show_ui(self):
        # command-driven menu (just to practice something different)
        # Lab7-9 oricare varianta (print-menu + optiuni/comenzi) este ok
        # dar si la comenzi sa existe un user guide, ce comenzi sunt dispobibile, cum le folosim
        while True:
            print('Comenzi disponibile: add, delete_by_id, delete_by_years, update, filter_by_no_eps,show_all, exit')
            cmd = input('Comanda este:')
            cmd = cmd.lower().strip()
            if cmd == 'add':
                self.__add_show()
            elif cmd == 'delete_by_id':
                self.__delete_show()
            elif cmd == 'update':
                self.__update_show()
            elif cmd == 'show_all':
                self.__print_shows(self.__srv.get_all_shows())
            elif cmd == 'delete_by_years':
                self.__delete_by_years()
            elif cmd == 'filter_by_no_eps':
                self.__filter_by_no_eps()
            elif cmd == 'exit':
                return
            else:
                print(colored('Comanda invalida.', 'red'))
