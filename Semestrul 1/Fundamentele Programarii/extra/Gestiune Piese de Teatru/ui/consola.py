class Consola:

    def __init__(self, service):
        self.__service = service

    def __ui_afisare(self):
        lista_piese = self.__service.get_all()
        for el in lista_piese:
            print(f"Piesa '{el.get_titlu()}', regizata de {el.get_regizor()}, este de genul: {el.get_gen()}, si dureaza {el.get_durata()} secunde")

    def __ui_adauga(self):
        try:
            titlu = input("Titlu: ")
            regizor = input("Regizor: ")
            gen = input("Gen: ")
            durata = int(input("Durata: "))
            self.__service.adauga_piesa(titlu, regizor, gen, durata)
        except ValueError:
            print("Date invalide!")
        except Exception as e:
            print(str(e))

    def __ui_modifica(self):
        try:
            titlu = input("Titlul piesei de treatru ce se vrea modificata: ")
            regizor = input("Regizorul piesei ce se vrea modificata: ")
            print("Modificare gen si durata")
            gen = input("Genul piesei: ")
            durata = int(input("Durata piesei: "))
            self.__service.modifica_piesa(titlu, regizor, gen, durata)
        except ValueError:
            print("Date invalide!")
        except Exception as e:
            print(str(e))

    def __ui_random(self):
        try:
            numar_piese = int(input("Numarul de piese pe care le vreti adaugate aleator: "))
            self.__service.random(numar_piese)
        except ValueError:
            print("Date invalide!")

    def __ui_export(self):
        try:
            fisier = input("Numele fisierului in care sa se exporte piesele de teatru: ")
            self.__service.export("data/"+fisier)
        except ValueError:
            print("Date invalide!")

    def run(self):
        while True:
            print("0. Afisare piese de teatru")
            print("1. Adaugare piesa de teatru")
            print("2. Modificare piesa de teatru")
            print("3. Creeaza aleator piese de teatru")
            print("4. Exporta piese de teatru sortate dupa regizor si titlu intr-un fisier text")
            optiune = input("Optiunea este: ")
            match optiune:
                case '0':
                    print("---")
                    self.__ui_afisare()
                    print("---")
                case '1':
                    print("---")
                    self.__ui_adauga()
                    print("---")
                case '2':
                    print("---")
                    self.__ui_modifica()
                    print("---")
                case '3':
                    print("---")
                    self.__ui_random()
                    print("---")
                case '4':
                    print("---")
                    self.__ui_export()
                    print("---")
                case 'exit':
                    return
                case other:
                    continue