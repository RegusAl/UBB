class Consola:

    def __init__(self, service):
        self.__service = service
        self.crt_undo = []

    def adaugare_produs(self):
        '''
        Adauga un produs nou
        :return: -
        '''
        id = int(input("ID: "))
        denumire = input("Denumire: ")
        pret = float(input("Pret: "))
        self.__service.adaugare_produs(id, denumire, pret)

    def stergere_produse(self):
        '''
        Sterge produsele
        :return: -
        '''
        cifra = int(input("Stegere: "))
        self.crt_undo = self.__service.update_undo(self.crt_undo, cifra)
        print(f" S-au sters {self.__service.stergere_produse(cifra)} produse ce contineau in id cifra {cifra}")

    def filtrare_produse(self):
        '''
        Filtreaza produsele in functie de denumire si pret
        :return: -
        '''
        filtru_denumire = input("Filtru denumire: ")
        filtru_pret = int(input("Filtru pret: "))
        print(f"Filtru curent: {filtru_denumire}, {filtru_pret}")
        for el in self.__service.filtrare(filtru_denumire, filtru_pret):
            print(f"{el.get_id()}: {el.get_denumire()} costa {el.get_pret()}")

    def undo(self):
        try:
            self.__service.undo(self.crt_undo)
        except ValueError as ve:
            print(ve)

    def start(self):
        while True:
            optiune = input("Optiunea dumneavoastra: ")
            match optiune:
                case '1':
                    print("Adaugare produs nou")
                    self.adaugare_produs()
                case '2':
                    print("Stergere produse")
                    self.stergere_produse()
                case '3':
                    self.filtrare_produse()
                case '4':
                    self.undo()
                case 'exit':
                    return
                case other:
                    continue