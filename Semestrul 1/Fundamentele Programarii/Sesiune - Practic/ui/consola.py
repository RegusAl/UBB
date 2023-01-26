from datetime import datetime


class Consola:

    def __init__(self, service):
        self.__service = service

    def get_all(self):
        for el in self.__service.get_all():
            print(f"{el.get_id()}")

    def __ui_adaugare_tractor(self):
        print("---Adaugare tractor---")
        id = int(input("ID: "))
        denumire = input("Denumire: ")
        pret = int(input("Pret: "))
        model = input("Model: ")
        data = input("Data: ")
        self.__service.adaugare_tractor(id, denumire, pret, model, data)

    def __ui_stergere_tractoare(self):
        print("---Stergere tractor---")
        cifra = int(input("Cifra: "))
        numar_sters = self.__service.stergere_tractoare(cifra)
        print(f"S-au sters {numar_sters} tractoare.")

    def __ui_filtrare(self, denumire, pret):
        print(f"Filtru curent: Denumire - {denumire}, Pret - {pret}")
        tractoare_filtrate = self.__service.filtrare(denumire, pret)
        for el in tractoare_filtrate:
            print(f"{el.get_id()}: {el.get_denumire()} are pretul {el.get_pret()} pentru modelul {el.get_model()}. Revizia expira: {el.get_data()}")
        return tractoare_filtrate



    def start(self):
        denumire = ""
        pret = 0
        ok = 0
        while True:
            if ok == 1:
                self.__ui_filtrare(denumire, pret)
            optiune = input("Optiune: ")
            match optiune:
                case '1':
                    self.__ui_adaugare_tractor()
                case '2':
                    self.__ui_stergere_tractoare()
                case '3':
                    denumire = input("Denumirea dupa care vreti sa filtrati: ")
                    pret = int(input("Pretul dupa care vreti sa filtrati (sau -1 pentru a nu filtra dupa pret): "))
                    self.__ui_filtrare(denumire, pret)
                    ok = 1
                case 'afisare':
                    self.get_all()
                case 'exit':
                    return
                case other:
                    continue