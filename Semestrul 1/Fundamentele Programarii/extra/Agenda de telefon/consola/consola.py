


class Consola:

    def __init__(self, service):
        self.__service = service

    def __ui_adauga_contact(self):
        '''
        Functia ui ce adauga un contact nou
        :return: -
        :raises: ValueError daca datele nu sunt valide
        '''
        try:
            print("---Adaugare Contact---")
            id = int(input("ID: "))
            nume = input("Nume: ")
            nrTelefon = int(input("Numar de telefon: "))
            grup = input("Grup: ")
            self.__service.adauga_contact(id, nume, nrTelefon, grup)
        except ValueError as ve:
            print(ve)

    def __ui_cautare_numar_telefon(self):
        '''
        Functia ui ce cauta un numar de telefon in functie de numele contactului
        :return: -
        :raises: ValueError daca numele nu exista
        '''
        try:
            nume = input("Numele contactului pe care il cautati: ")
            date = self.__service.cautare_numar_telefon(nume)
            print(f"{date.get_id()}: {date.get_nume()} {date.get_nrTelefon()} ")
        except ValueError as ve:
            print(ve)

    def __ui_sortare_grup(self):
        '''
        Functia ui ce afiseaza grupul sortat dupa nume
        :return: -
        :raises: ValueError daca grupul nu exista
        '''
        try:
            grup = input("Grupul: ")
            date = self.__service.sortare_grup(grup)
            print(f"---Grupul {grup}---")
            for el in date:
                print(f"{el.get_id()}: {el.get_nume()} are numarul {el.get_nrTelefon()}")
        except ValueError as ve:
            print(ve)

    def __ui_export(self):
        '''
        Functia ce exporta grupul dat de utitlizator intr-un fisier CSV
        :return: -
        '''
        print("---Export---")
        grup = input("Grupul de exportat: ")
        self.__service.export(grup)

    def start(self):
        while True:
            optiune = input("Optiunea: ")
            match optiune:
                case '1':
                    self.__ui_adauga_contact()
                case '2':
                    self.__ui_cautare_numar_telefon()
                case '3':
                    self.__ui_sortare_grup()
                case '4':
                    self.__ui_export()
                case 'exit':
                    return
                case other:
                    continue