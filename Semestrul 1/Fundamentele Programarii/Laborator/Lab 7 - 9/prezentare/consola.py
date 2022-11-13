from erori.repo_error import RepoError
from erori.validation_error import ValidError

class ui:

    def __init__(self, service_filme, service_clienti, service_inchiriere):
        '''
        Initializeaza consola
        :param service_filme: srv pentru filme
        :param service_clienti: srv pentru clienti
        :param service_inchiriere: srv pentru inchiriere
        '''
        self.__service_filme = service_filme
        self.__service_clienti = service_clienti
        self.__service_inchiriere = service_inchiriere

    ## UI pentru FILM


    ### Adauga Film
    def __ui_adauga_film(self):
        '''
        Functia ui ce primeste datele de la utilizator pentru a adauga un film
        '''
        try:
            id_film = int(input("ID: "))
            nume_film = input("Nume film: ")
            gen_film = input("Gen: ")
            self.__service_filme.adauga_film(id_film, nume_film, gen_film)
            print("Film adaugat cu succes!")
        except RepoError:
            print("Film existent!")
        except:
            print("Datele filmului nu sunt valide!")

    ### Afisare Filme
    def __ui_afisare_filme(self):
        '''
        Functia ui ce afiseaza filmele
        '''
        lista_filme = self.__service_filme.afisare_filme()
        print("Filme:")
        for el in lista_filme:
            print(f"{el[0]}: {el[1]}; Genul filmului: {el[2]}")

    ### Sterge film dupa id
    def __ui_sterge_film_id(self):
        '''
        Functia ui ce sterge filmul in functie de id-ul dat de utilizator
        '''
        try:
            id_film = int(input("ID-ul filmului pe care vreti sa-l stergeti: "))
            self.__service_filme.sterge_film_dupa_id(id_film)
        except RepoError:
            print("ID-ul nu exista!")
        except:
            print("ID-ul nu este valid!")

    # MENU

    def __meniu_principal(self):
        print("1. Meniul cu Filmele")
        print("2. Meniul cu Clientii")
        print("0. Exit")

    def __meniu_film(self):
        print("1. Adauga Film")
        print("2. Afisare Filme")
        print("3. Sterge Film")

    def __ui_filme(self):
        optiune = input("Optiunea dumneavoastra: ")
        match optiune:
            case '1':
                self.__ui_adauga_film()
            case '2':
                self.__ui_afisare_filme()
            case '3':
                self.__ui_sterge_film_id()
            case other:
                print("Optiune invalida!")
                return

    def run(self):
        while True:
            self.__meniu_principal()
            comanda = input("Optiunea dumneavoastra: ")
            match comanda:
                case '1':
                    self.__meniu_film()
                    self.__ui_filme()
                case '0':
                    return
                case other:
                    print("Optiune invalida!")
