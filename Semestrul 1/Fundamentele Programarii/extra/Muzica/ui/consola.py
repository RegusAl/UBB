from erori.erori import ValidError


class Consola:

    def __init__(self, service, repo):
        self.__service = service
        self.__repo = repo


    def afisare_melodii(self):
        '''
        Functia ui ce afiseaza melodiile
        :return: -
        '''
        for el in self.__repo.get_all():
            print(f"Melodia {el.get_titlu()} de {el.get_artist()} este de genul {el.get_gen()} si are durata de {el.get_durata()}")

    def modificare_melodii(self):
        '''
        Functia ui ce modifica genul si durata melodiei
        :return: -
        '''
        try:
            titlu = input("Titlu: ")
            artist = input("Artist: ")
            gen = input("Gen: ")
            durata = int(input("Durata: "))
            self.__service.modificare_melodie(titlu, artist, gen, durata)
        except ValidError as ve:
            print(ve)
        except ValueError:
            print("Date invalide!")

    def melodii_random(self):
        '''
        Functia ui ce creeaza aleator melodii
        :return: -
        '''
        try:
            numar = int(input("Numarul de melodii: "))
            titluri = input("Titlurile: ")
            lista_titluri = titluri.split(",")
            artistii = input("Artistii: ")
            lista_artisti = artistii.split(",")
            self.__service.melodii_random(numar, lista_titluri, lista_artisti)
        except ValueError:
            print("Date invalide!")

    def export(self):
        nume_fisier = input("Dati numele fisierului in care vreti sa exportati: ")
        self.__service.export(nume_fisier)

    def run(self):
        while True:
            optiune = input("Optiunea dumneavoastra: ")
            match optiune:
                case '1':
                    self.modificare_melodii()
                case '2':
                    self.melodii_random()
                case '3':
                    self.export()
                case 'afisare':
                    self.afisare_melodii()
                case 'exit':
                    return