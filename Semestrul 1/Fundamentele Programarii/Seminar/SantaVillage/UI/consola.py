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

    def __ui_organizare_atelier(self):
        try:
            atelier = input("Atelier: ")
            numar_zile = int(input("Numar Zile: "))
            atelier_organizat = self.__service.organizare_atelier(atelier, numar_zile)
            print(f"In atelierul {atelier_organizat[0]} din locatia: {atelier_organizat[2]}, unde lucreaza {atelier_organizat[1]} de spiridusi, se pot procesa intre {atelier_organizat[3]} - {atelier_organizat[4]} produse")
        except ValueError:
            print("Date invalide!")
        except Exception as e:
            print(str(e))

    def run(self):
        while True:
            print("1. Afisare ateliere")
            print("2. Afisare ateliere cu un produs dat de utilizator si cu numar de spiridusi mai mare decat un numar dat")
            print("3. Afisare numar de produse ce pot fi procesate intr-un atelier")
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
                case '3':
                    print("---")
                    self.__ui_organizare_atelier()
                    print("---")
                case 'exit':
                    return
                case other:
                    continue