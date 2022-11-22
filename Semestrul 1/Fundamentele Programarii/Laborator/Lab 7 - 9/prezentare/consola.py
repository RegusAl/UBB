# from domeniu.filme import get_id_film, get_nume_film, get_gen_film
from erori.repo_error import RepoError
import random

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
            film_adaugat = self.__service_filme.adauga_film(id_film, nume_film, gen_film)
            print(f"Filmul {film_adaugat.get_nume_film()} adaugat cu succes!")
        except RepoError:
            print("Film existent!")
        except:
            print("Datele filmului nu sunt valide!")

    ### Afisare Filme
    def __ui_afisare_filme(self, lista):
        '''
        Functia ui ce afiseaza filmele
        '''
        print("------------")
        print("---Filme:---")
        for el in lista:
            print(f"{el.get_id_film()}: {el.get_nume_film()}; Genul filmului: {el.get_gen_film()}")
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

    ### Cauta film dupa id
    def __ui_cauta_film_id(self):
        '''
        Functia ui ce cauta un film dupa id
        '''
        try:
            id_film = int(input("ID-ul filmului pe care il cautati: "))
            el = self.__service_filme.cauta_film_dupa_id(id_film)
            print(f"{el.get_id_film()}: {el.get_nume_film()}; Genul filmului: {el.get_gen_film()}")
        except RepoError:
            print("Filmul cu acest ID nu exista!")
        except:
            print("ID-ul filmului nu este valid!")

    def __ui_film_random(self):
        number = random.randint(1, 10)
        self.__service_filme.filme_random(number)
        print(f"S-au generat {number} filme random!")

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
            print(f"{el.get_id_client()}: NUME: {el.get_nume_client()}; CNP: {el.get_cnp_client()}")
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

    ### Cauta client dupa id
    def __ui_cauta_client_id(self):
        '''
        Functia ui ce cauta un client dupa id
        '''
        try:
            id_client = int(input("ID-ul clientului pe care il cautati: "))
            el = self.__service_clienti.cauta_client_dupa_id(id_client)
            print(f"{el.get_id_client()}: {el.get_nume_client()}; Genul filmului: {el.get_cnp_client()}")
        except RepoError:
             print("Clientul cu acest ID nu exista!")
        except:
            print("ID-ul clientului nu este valid!")

    def __ui__client_random(self):
        number = random.randint(1, 10)
        self.__service_clienti.clienti_random(number)
        print(f"S-au generat {number} clienti random!")


    ### INCHIRIERE
    def __ui_inchiriere(self):
        try:
            id_client = int(input("ID-ul clientului ce vrea sa inchirieze: "))
            id_film = int(input("ID-ul filmului pe care clientul vrea sa-l inchirieze: "))
            self.__service_inchiriere.inchiriere(id_client, id_film)
        except RepoError as ve:
            print(ve)
        except:
            print("ID-ul nu este valid!")

    #### Afisare inchiriere
    def __ui_afisare_inchiriere(self):
        print("----Lista de Inchirieri----")
        lista_inchirieri = self.__service_inchiriere.afisare_inchiriere()
        for el in lista_inchirieri:
            client = self.__service_clienti.cauta_client_dupa_id(el.get_client())
            film = self.__service_filme.cauta_film_dupa_id(el.get_film())
            print(f"{client.get_id_client()}: {client.get_nume_client()} a inchiriat {film.get_nume_film()}")
        print("---------------------------")

    ### RETURNARE
    def __ui_returnare(self):
        try:
            id_client = int(input("ID-ul clientului ce vrea sa returneze: "))
            id_film = int(input("ID-ul filmului pe care clientul vrea sa-l returneze: "))
            self.__service_inchiriere.returnare(id_client, id_film)
        except RepoError as ve:
            print(ve)
        except:
            print("ID-ul nu este valid!")


    # MENIURI

    def __meniu_principal(self):
        print("1. Meniul cu Filmele")
        print("2. Meniul cu Clientii")
        print("3. Meniul cu inchirieri")
        print("0. Exit")

    def __meniu_film(self):
        print("-----FILM-----")
        print("1. Adauga Film")
        print("2. Afisare Filme")
        print("3. Sterge Film dupa ID")
        print("4. Modifica Film dupa ID")
        print("5. Cautare Film dupa ID")
        print("6. Genereaza filme random")
        print("--------------")

    def __meniu_clienti(self):
        print("-----CLIENTI-----")
        print("1. Adauga Client")
        print("2. Afisare Clienti")
        print("3. Stergere Client dupa ID")
        print("4. Modifica Client dupa ID")
        print("5. Cautare Client dupa ID")
        print("6. Genereaza clienti random")
        print("-----------------")

    def __meniu_inchirieri(self):
        print("----INCHIRIERI si RETURNARI----")
        print("1. Adauga inchiriere")
        print("2. Afisare inchirieri")
        print("3. Returnare")
        print("-------------------------------")

    def __ui_filme(self):
        optiune = input("Optiunea dumneavoastra: ")
        match optiune:
            case '1':
                self.__ui_adauga_film()
            case '2':
                self.__ui_afisare_filme(self.__service_filme.afisare_filme())
            case '3':
                self.__ui_sterge_film_id()
            case '4':
                self.__ui_modifica_film_id()
            case '5':
                self.__ui_cauta_film_id()
            case '6':
                self.__ui_film_random()
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
            case '5':
                self.__ui_cauta_client_id()
            case '6':
                self.__ui__client_random()
            case other:
                print("Optiune invalida!")
                return

    def __ui_inchirieri(self):
        optiune = input("Optiunea dumneavoastra: ")
        match optiune:
            case '1':
                self.__ui_inchiriere()
            case '2':
                self.__ui_afisare_inchiriere()
            case '3':
                self.__ui_returnare()
            case other:
                print("Optiune invalida!")
                return


    # Functia run() ce apeleaza toate meniurile
    def run(self):
        while True:
            print("----MENIU----")
            self.__meniu_principal()
            comanda = input("Optiunea dumneavoastra: ")
            match comanda:
                case '1':
                    self.__meniu_film()
                    self.__ui_filme()
                case '2':
                    self.__meniu_clienti()
                    self.__ui_client()
                case '3':
                    self.__meniu_inchirieri()
                    self.__ui_inchirieri()
                case '0':
                    print("!Ati iesit din program!")
                    return
                case other:
                    print("Optiune invalida!")
            print("-------------")