class Consola:

    def __init__(self, service):
        '''
        initializare
        '''
        self.__service = service

    def __ui_adaugare_tractor(self):
        '''
        Functia ui ce adauga un tractor nou
        :return: -
        '''
        print("---Adaugare tractor---")
        id = int(input("ID: "))
        denumire = input("Denumire: ")
        pret = int(input("Pret: "))
        model = input("Model: ")
        data = input("Data: ")
        self.__service.adaugare_tractor(id, denumire, pret, model, data)

    def __ui_stergere_tractoare(self):
        '''
        Functia ui de stergere a tractoarelor ce au in pret cifra data de utilizator
        :return: -
        '''
        print("---Stergere tractor---")
        cifra = int(input("Cifra: "))
        numar_sters = self.__service.stergere_tractoare(cifra)
        print(f"S-au sters {numar_sters} tractoare.")

    def __ui_filtrare(self, denumire, pret):
        '''
        Functia ui de filtrare a tractoarelor in functie de denumire si pret
        :param denumire: denumirea tractoarelor dupa care se filtreaza
        :param pret: pretul dupa care se filtreaza
        :return: tractoarele filtrate
        '''
        print("---FILTRARE---")
        print(f"Filtru curent: Denumire - {denumire}, Pret - {pret}")
        tractoare_filtrate = self.__service.filtrare(denumire, pret)
        for el in tractoare_filtrate:
            print(f"{el.get_id()}: {el.get_denumire()} are pretul {el.get_pret()} pentru modelul {el.get_model()}. Revizia expira: {el.get_data()}")
        return tractoare_filtrate

    def __ui_undo(self):
        '''
        Functia ui ce face undo la ultima operatie efectuata
        :return: -
        '''
        print("---UNDO---")
        self.__service.undo()

    def start(self):
        denumire = ""
        pret = -1
        ok = 0
        while True:
            self.__ui_filtrare(denumire, pret)
            print("---------------\n MENIU \n---------------")
            print("1. Adaugare Tractor\n2. Stergere Tractor\n3. Filtrare Tractor\n4. UNDO\nx - Exit")
            print("---------------")
            optiune = input("Optiune: ")
            match optiune:
                case '1':
                    self.__ui_adaugare_tractor()
                case '2':
                    self.__ui_stergere_tractoare()
                case '3':
                    denumire = input("Denumirea dupa care vreti sa filtrati: ")
                    pret = int(input("Pretul dupa care vreti sa filtrati (sau -1 pentru a nu filtra dupa pret): "))
                    #self.__ui_filtrare(denumire, pret)
                case '4':
                    self.__ui_undo()
                case 'x':
                    return
                case other:
                    continue