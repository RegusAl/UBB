class Consola:

    def __init__(self, service):
        self.__service = service

    def __ui_afisare_prognoze(self):
        '''
        Afiseaza toate prognozele
        :return: -
        '''
        elemente = self.__service.get_all()
        for el in elemente:
            print(
                f"id: {el.get_id()}, data: {el.get_data()}, locatia: {el.get_locatia()}, prognoza: {el.get_prognoza()}, {el.get_temp_minima()}/{el.get_temp_maxima()}")

    def __ui_afisare_locatii_string(self):
        '''
        Afiseaza toate prognozele ce au in componenta lor stringul dat de utitlizator
        :return: -
        :except: repoerror daca nu exista
        '''
        try:
            locatie = input("Dati stringul dupa care vreti locatia: ")
            prognoze = self.__service.locatii_string(locatie)
            for el in prognoze:
                print(f"id: {el.get_id()}, data: {el.get_data()}, locatia: {el.get_locatia()}, prognoza: {el.get_prognoza()}, {el.get_temp_minima()}/{el.get_temp_maxima()}")
        except ValueError:
            print("Date invalide")
        except:
            print("Nu exista locatie ce contine acest string!")

    def __ui_grupare_dupa_locatie(self):
        locatii = self.__service.grupare_locatie()
        for el in locatii:
            print("---")
            for key, value in el.items():
                print(key, ": ", value)
        print("---")

    def run(self):
        while True:
            print("1. Afisare tuturor prognozelor ce contin un anumit string, sortate descrescator dupa data")
            print("2. Grupare dupa locatie")
            print("3. Afisearea tuturor prognozelor")
            optiune = input("Optiune: ")
            match optiune:
                case '1':
                    self.__ui_afisare_locatii_string()
                case '2':
                    self.__ui_grupare_dupa_locatie()
                case '3':
                    self.__ui_afisare_prognoze()
                case 'exit':
                    return
                case other:
                    continue