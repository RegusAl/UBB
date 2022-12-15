class Atelier:

    def __init__(self, nume, locatie, produs, numar_spiridusi):
        self.__nume = nume
        self.__locatie = locatie
        self.__produs = produs
        self.__numar_spiridusi = numar_spiridusi

    def get_nume(self):
        return self.__nume

    def get_locatie(self):
        return self.__locatie

    def get_produs(self):
        return self.__produs

    def get_numar_spiridusi(self):
        return self.__numar_spiridusi