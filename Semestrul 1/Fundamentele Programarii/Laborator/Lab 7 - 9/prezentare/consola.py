from domeniu.clienti import get_id_client, get_nume_client, get_cnp_client
from domeniu.filme import get_id_film, get_nume_film, get_gen_film
from erori.repo_error import RepoError
#from erori.validation_error import ValidError

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
        print("------------")
        print("---Filme:---")
        for el in lista_filme:
            print(f"{get_id_film(el)}: {get_nume_film(el)}; Genul filmului: {get_gen_film(el)}")
        print("------------")

    ### Sterge film dupa id
    def __ui_sterge_film_id(self):
        '''
        Functia ui ce sterge filmul in functie de id-ul dat de utilizator
        '''
        try:
            id_film = int(input("ID-ul filmului pe care vreti sa-l stergeti: "))
            self.__service_filme.sterge_film_dupa_id(id_film)
            print("Filmul a fost sters cu succes!")
        except RepoError:
            print("ID-ul filmului nu exista!")
        except:
            print("Filmul nu este valid!")

    ### Modifica film dupa id
    def __ui_modifica_film_id(self):
        '''
        Functia ui ce modifica filmul in functie de id-ul dat de utilizator
        '''
        try:
            id_film = int(input("ID-ul filmului pe care vreti sa-l modificati: "))
            self.__service_filme.sterge_film_dupa_id(id_film)
            nume_film = input("Nume film: ")
            gen_film = input("Gen: ")
            self.__service_filme.adauga_film(id_film, nume_film, gen_film)
        except RepoError:
            print("ID-ul filmului nu exista!")
        except:
            print("ID-ul filmului nu este valid!")

    ## UI pentru Clienti

    ### Adauga Clienti
    def __ui_adauga_client(self):
        '''
        Functia ui ce adauga client
        :return:
        '''
        try:
            id_client = int(input("ID: "))
            nume_client = input("Nume client: ")
            cnp_client = int(input("CNP: "))
            self.__service_clienti.adauga_client(id_client, nume_client, cnp_client)
            print("Client adaugat cu succes!")
        except RepoError:
            print("Client existent!")
        except:
            print("Datele clientului invalide!")

    ### Afiseaza Clienti
    def __ui_afisare_client(self):
        '''
        Functia ui ce afiseaza filmele
        '''
        lista_clienti = self.__service_clienti.afisare_clienti()
        print("------------")
        print("---Clienti:---")
        for el in lista_clienti:
            print(f"{get_id_client(el)}: NUME: {get_nume_client(el)}; CNP: {get_cnp_client(el)}")
        print("------------")

    ### Sterge client dupa ID
    def __ui_sterge_client_id(self):
        '''
        Functia ui ce sterge un client dupa id
        '''
        try:
            id_client = int(input("ID-ul clientului pe care vreti sa-l stergeti: "))
            self.__service_clienti.sterge_client_dupa_id(id_client)
            print("Clientul a fost sters cu succes!")
        except RepoError:
            print("ID-ul clientului nu exista!")
        except:
            print("ID-ul clientului nu este valid!")

    ### Modifica client dupa ID
    def __ui_modifica_client_id(self):
        '''
        Functia ui ce modifica clientul in functie de id-ul dat de utilizator
        '''
        try:
            id_client = int(input("ID-ul clientului pe care vreti sa-l modificati: "))
            self.__service_clienti.sterge_client_dupa_id(id_client)
            nume_client = input("Nume client: ")
            cnp_client = int(input("CNP: "))
            self.__service_clienti.adauga_client(id_client, nume_client, cnp_client)
        except RepoError:
            print("ID-ul clientului nu exista!")
        except:
            print("Datele clientului nu sunt valide!")

    # MENIURI

    def __meniu_principal(self):
        print("1. Meniul cu Filmele")
        print("2. Meniul cu Clientii")
        print("0. Exit")

    def __meniu_film(self):
        print("1. Adauga Film")
        print("2. Afisare Filme")
        print("3. Sterge Film dupa ID")
        print("4. Modifica Film dupa ID")

    def __meniu_clienti(self):
        print("1. Adauga Client")
        print("2. Afisare Clienti")
        print("3. Stergere Client dupa ID")
        print("4. Modifica Client dupa ID")

    def __ui_filme(self):
        optiune = input("Optiunea dumneavoastra: ")
        match optiune:
            case '1':
                self.__ui_adauga_film()
            case '2':
                self.__ui_afisare_filme()
            case '3':
                self.__ui_sterge_film_id()
            case '4':
                self.__ui_modifica_film_id()
            case other:
                print("Optiune invalida!")
                return

    def __ui_client(self):
        optiune = input("Optiunea dumneavoastra: ")
        match optiune:
            case '1':
                self.__ui_adauga_client()
            case '2':
                self.__ui_afisare_client()
            case '3':
                self.__ui_sterge_client_id()
            case '4':
                self.__ui_modifica_client_id()
            case other:
                print("Optiune invalida!")
                return

    # Functia run() ce apeleaza toate meniurile
    def run(self):
        while True:
            self.__meniu_principal()
            comanda = input("Optiunea dumneavoastra: ")
            match comanda:
                case '1':
                    self.__meniu_film()
                    self.__ui_filme()
                case '2':
                    self.__meniu_clienti()
                    self.__ui_client()
                case '0':
                    print("!Ati iesit din program!")
                    return
                case other:
                    print("Optiune invalida!")
