class Consola:

    def __init__(self, service):
        self.__service = service

    def __ui_afisare_ateliere(self):
        ateliere = self.__service.get_all()
        for atelier in ateliere:
            print(f"In ateliereul {atelier.get_nume()} din {atelier.get_locatie()} lucreaza {atelier.get_numar_spiridusi()} de spiridusi pentru {atelier.get_produs()}")

    def __ui_cautare_atelier(self):
        ateliere = []
        try:
            produs = input("Produsul cautat: ")
            numar_spiridusi = int(input("Numar minim de spiridusi: "))
            ateliere = self.__service.cautare_atelier(produs, numar_spiridusi)
        except ValueError:
            print("Date invalide!")
        except Exception as e:
            print(str(e))
        for atelier in ateliere:
            print(f"In ateliereul {atelier.get_nume()} din {atelier.get_locatie()} lucreaza {atelier.get_numar_spiridusi()} de spiridusi pentru {atelier.get_produs()}")


    def run(self):
        while True:
            print("1. Afisare ateliere")
            print("2. Afisare ateliere cu un produs dat de utilizator si cu numar de spiridusi mai mare decat un numar dat")
            optiune = input("Optiune: ")
            match optiune:
                case '1':
                    print("---")
                    self.__ui_afisare_ateliere()
                    print("---")
                case '2':
                    print("---")
                    self.__ui_cautare_atelier()
                    print("---")
                case 'exit':
                    return
                case other:
                    continue