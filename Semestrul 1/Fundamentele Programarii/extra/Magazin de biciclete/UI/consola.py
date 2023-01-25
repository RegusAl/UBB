class Consola:

    def __init__(self,  service):
        self.__service = service


    def __ui_afisare(self):
        produse = self.__service.get_all()
        for el in produse:
            print(f"{el.get_id_bicicleta()}: {el.get_tip()} ({el.get_pret()} $)")

    def __ui_sterge_tip(self):
        tip = input("Tipul de bicicleta pe care vreti sa-l stergeti: ")
        self.__service.sterge_tip(tip)

    def __ui_sterge_max(self):
        self.__service.sterge_max()

    def start(self):
        while True:
            print("1. Afisare\t\t2. Stergere dupa tip\t\t3. Stergere max\t\tx - Exit")
            optiune = input("Optiune: ")
            match optiune:
                case '1':
                    self.__ui_afisare()
                case '2':
                    self.__ui_sterge_tip()
                case '3':
                    self.__ui_sterge_max()
                case 'x':
                    return
                case other:
                    continue