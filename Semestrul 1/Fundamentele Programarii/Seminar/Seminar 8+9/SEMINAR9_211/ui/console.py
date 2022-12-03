from termcolor import colored

from exceptions.exceptions import ValidationException, DuplicateIDException, ClientNotFoundException, \
    ShowNotFoundException, RatingAlreadyAssignedException, NotEnoughRatingsException


class Console:
    def __init__(self, srv_shows, srv_clients, srv_ratings):
        """
        Initializeaza consola
        :type srv: ShowService
        """
        self.__srv_shows = srv_shows
        self.__srv_clients = srv_clients
        self.__srv_ratings = srv_ratings

    def __print_menu(self):
        print('Comenzi disponibile pentru show, client. Adaugati sufixul',
              colored('_show sau _client', 'magenta'), ' pentru a accesa optiunea dorita.')
        print('ENTITY COMMANDS:', colored('add, delete, update, show_all', 'green'))
        print('Comenzi disponibile pentru rating-uri. Se folosesc fara adaugare string.')
        print('RATING COMMANDS:',
              colored('assign_rating, top3_shows_by_client, show_all_ratings, rating_report, exit', 'green'))

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
            added_show = self.__srv_shows.add_show(id, titlu, an_aparitie, eps)
            print('Serialul ' + added_show.getTitle() + ' (' + str(
                added_show.getAnAparitie()) + ') a fost adaugat cu succes.')
        except ValueError:
            print(colored('Anul aparitiei si nr. episoade trebuie sa fie un numar.', 'red'))
        except ValidationException as ve:
            print(colored(str(ve), 'red'))
        except DuplicateIDException as e:
            print(colored(str(e), 'red'))

    def __delete_show(self):
        id = input('Identificatorul serialului de sters:')
        try:
            deleted_show = self.__srv_shows.delete_show(id)
            print('Serialul ' + deleted_show.getTitle() + ' (' + str(
                deleted_show.getAnAparitie()) + ') a fost sters cu succes (ID=' + str(deleted_show.getId()) + ').')
        except ShowNotFoundException as e:
            print(colored(str(e), 'red'))

    def __update_show(self):
        id = input('Identificator serial:')
        titlu = input("Titlul serialului:")
        try:
            an_aparitie = int(input("Anul aparitiei:"))
            eps = int(input("Numar de episoade difuzate:"))
            modified_show = self.__srv_shows.update_show(id, titlu, an_aparitie, eps)
            print('Serialul ' + modified_show.getTitle() + ' (' + str(
                modified_show.getAnAparitie()) + ') a fost modificat cu succes.')
        except ValueError:
            print(colored('Anul aparitiei si nr. episoade trebuie sa fie un numar.', 'red'))
        except ValidationException as ve:
            print(colored(str(ve), 'red'))
        except ShowNotFoundException as e:
            print(colored(str(e), 'red'))

    def __print_clients(self, client_list):
        """
        Afiseaza o lista de clienti

        """

        if len(client_list) == 0:
            print('Nu exista clienti in lista.')
        else:
            print('Lista de clienti este:')
            for client in client_list:
                # print(client)
                print('ID: ', colored(client.getId(), 'cyan'),
                      ' - Nume client: ', colored(client.getNume(), 'cyan'), ' - Varsta: ',
                      colored(str(client.getVarsta()),
                              'cyan'))

    def __add_client(self):
        """
        Adauga un client cu datele citite de la tastatura
        """
        id = input('Identificator client:')
        nume = input("Numele clientului:")
        try:
            varsta = int(input("Varsta:"))
            added_client = self.__srv_clients.add_client(id, nume, varsta)
            print('Clientul ' + added_client.getNume() + ' cu varsta ' + str(
                added_client.getVarsta()) + ' a fost adaugat cu succes.')
        except ValueError:
            print(colored('Varsta clientului trebuie sa fie un numar.', 'red'))
        except ValidationException as ve:
            print(colored(str(ve), 'red'))
        except DuplicateIDException as e:
            print(colored(str(e), 'red'))

    def __delete_client(self):
        id = input('Identificatorul clientului de sters:')
        try:
            deleted_client = self.__srv_clients.delete_client(id)
            print('Clientul ', deleted_client, 'a fost sters cu succes (ID=' + str(deleted_client.getId()) + ').')

        except ClientNotFoundException as e:
            print(colored(str(e), 'red'))

    def __update_client(self):
        id = input('Identificator client:')
        nume = input("Numele clientului:")
        try:
            varsta = int(input("Varsta:"))
            modified_client = self.__srv_clients.update_client(id, nume, varsta)
            print('Clientul ' + modified_client.getNume() + ' cu varsta ' + str(
                modified_client.getVarsta()) + ' a fost modificat cu succes.')
        except ValueError:
            print(colored('Varsta clientului trebuie sa fie un numar.', 'red'))
        except ValidationException as ve:
            print(colored(str(ve), 'red'))
        except ClientNotFoundException as e:
            print(colored(str(e), 'red'))

    def __print_ratings(self, rating_list):
        """
        Afiseaza o lista de rating-uri

        """

        if len(rating_list) == 0:
            print('Nu exista rating-uri in lista.')
        else:
            print('Lista de rating-uri este:')
            for rating in rating_list:
                # print(rating)
                print('Serial: [', colored(str(rating.getSerialId()), 'cyan'), ']',
                      'Client: [', colored(str(rating.getClientId()), 'magenta'),']', 'Rating: ', colored(str(
                        rating.getNoStars()), 'blue'))

    def __assign_rating(self):
        id_show = input('ID serial:')
        id_client = input('ID client')
        try:
            no_stars = float(input('Number of stars:'))
            rating = self.__srv_ratings.create_rating(id_show, id_client, no_stars)
            print('Rating-ul', rating, 'a fost adaugat cu succes.')
        except ValueError:
            print(colored('No. stars trebuie sa fie un numar.', 'red'))
        except ValidationException as ve:
            print(colored(str(ve), 'red'))
        except ShowNotFoundException as ve:
            print(colored(str(ve), 'red'))
        except ClientNotFoundException as ve:
            print(colored(str(ve), 'red'))
        except RatingAlreadyAssignedException as ve:
            print(colored(str(ve), 'red'))

    def __get_top_shows_for_client(self):
        """
        Afiseaza primele 3 show-uri pentru un client dat (in functie de rating)
        """
        client_id = input('ID client:')
        try:
            client_shows = self.__srv_ratings.get_top_shows(client_id)
            print('Primele 3 seriale cu cele mai bune rating-uri sunt:')
            for client_show in client_shows:
                print('Nume client:', colored(client_show.getNumeClient(), 'cyan'), '; Titlu serial:',
                      colored(client_show.getTitluSerial(), 'magenta'), '; Rating:',
                      colored(str(client_show.getNoStars()), 'blue'))

        except ClientNotFoundException as e:
            print(colored(str(e), 'red'))
        except NotEnoughRatingsException as e:
            print(colored('Nu exista destule seriale evaluate pentru a afisa statistica.', 'red'))

    def show_ui(self):
        while True:
            self.__print_menu()
            cmd = input('Comanda este:')
            cmd = cmd.lower().strip()
            if cmd == 'add_show':
                self.__add_show()
            elif cmd == 'delete_show':
                self.__delete_show()
            elif cmd == 'update_show':
                self.__update_show()
            elif cmd == 'show_all_shows':
                self.__print_shows(self.__srv_shows.get_all_shows())

            elif cmd == 'add_client':
                self.__add_client()
            elif cmd == 'delete_client':
                self.__delete_client()
            elif cmd == 'update_client':
                self.__update_client()
            elif cmd == 'show_all_clients':
                self.__print_clients(self.__srv_clients.get_all_clients())

            elif cmd == 'assign_rating':
                self.__assign_rating()
            elif cmd == 'show_all_ratings':
                self.__print_ratings(self.__srv_ratings.get_all())
            elif cmd == 'top3_shows_by_client':
                self.__get_top_shows_for_client()
            elif cmd == 'exit':
                return
            else:
                print(colored('Comanda invalida.', 'red'))
