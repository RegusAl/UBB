class Consola:

    def __init__(self, service):
        self.__service = service

    def __ui_adaugare_jucator(self):
        '''
        Functia UI ce adauga un jucator
        :return: -
        :raises: ValueError
        '''
        print("---Adaugare Jucator---")
        try:
            nume = input("Numele jucatorului: ")
            prenume = input("Prenumele jucatorului: ")
            inaltime = int(input("Inaltime: "))
            post = input("Post: ")
            self.__service.adaugare_jucator(nume, prenume, inaltime, post)
        except ValueError as ve:
            print(ve)

    def __ui_modifica_inaltime(self):
        '''
        Functia UI ce modifica inaltimea unui jucator
        :return: -
        '''
        print("---Modificare inaltime---")
        nume = input("Numele jucatorului: ")
        prenume = input("Prenumele jucatorului: ")
        inaltime = int(input("Inaltimea: "))
        self.__service.modifica_inaltime(nume, prenume, inaltime)

    def __ui_echipa(self):
        '''
        Functia UI ce formeaza o echipa valida
        :return: -
        '''
        print("Prenume\t\tNume\t\tPost\t\tInaltime")
        echipa = self.__service.echipa_valida()
        for el in echipa:
            print(f"{el.get_prenume()}\t\t{el.get_nume()}\t\t{el.get_post()}\t\t{el.get_inaltime()}")

    def __ui_import(self):
        '''
        Functia UI ce importa jucatori dintr-un fisier citit de la tastatura si afiseaza numarul celor adaugati
        :return: -
        '''
        nume_fisier = input("Numele fisierului: ")
        jucatori_adaugati = self.__service.import_jucatori(nume_fisier)
        print(jucatori_adaugati)

    def start(self):
        while True:
            optiune = input("Optiunea dumneavoastra: ")
            match optiune:
                case '1':
                    self.__ui_adaugare_jucator()
                case '2':
                    self.__ui_modifica_inaltime()
                case '3':
                    self.__ui_echipa()
                case '4':
                    self.__ui_import()
                case 'exit':
                    return
                case other:
                    continue
