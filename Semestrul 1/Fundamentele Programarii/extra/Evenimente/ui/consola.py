class Consola:

    def __init__(self, service):
        self.__service = service

    def __ui_afisare_evenimente_zi_curenta(self):
        '''
        Functia ui ce afiseaza elementele din ziua curenta
        :return -
        '''
        print("--- Evenimente zi curenta ---")
        for el in self.__service.evenimente_zi_curenta():
            print(f"{el.get_descriere()}")

    def __ui_adaugare_eveniment(self):
        '''
        Functia ui ce adauga un eveniment dat de utilizator
        :return: -
        :raises: ValueError - daca datele sunt invalide
        '''
        print("--- Adaugare Eveniment ---")
        try:
            data = input("Data: ")
            ora = input("Ora: ")
            descriere = input("Descriere: ")
            self.__service.adaugare_eveniment(data, ora, descriere)
        except ValueError as ve:
            print(ve)

    def __ui_stabilire_data(self):
        '''
        Functia ui ce afiseaza descrierea evenimentelor din data aleasa de catre utilizator
        :return: -
        '''
        data = input("Data: ")
        print(f"Evenimente {data}")
        evenimente = self.__service.stabilire_data(data)
        for el in evenimente:
            print(f"{el.get_descriere()}")

    def __ui_export(self):
        '''
        Functia ui ce primeste numele fisierului si un sir de caractere pentru a exporta evenimentele intr-un nou fisier
        :return: -
        '''
        nume_fisier = input("Numele fisierului: ")
        sir = input("Caracterele pe care le cautati in descrierea evenimenelor: ")
        self.__service.export(nume_fisier, sir)


    def start(self):
        self.__ui_afisare_evenimente_zi_curenta()
        while True:
            optiune = input("Optiunea dumneavoastra: ")
            match optiune:
                case '1':
                    self.__ui_adaugare_eveniment()
                case '2':
                    self.__ui_stabilire_data()
                case '3':
                    self.__ui_export()
                case 'exit':
                    return
                case other:
                    continue
