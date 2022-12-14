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

class EvaluatorAtelier:

    def __init__(self, atelier, numar_zile):
        self.__atelier  = atelier
        self.__numar_zile = numar_zile
        self.__nr_min = 0
        self.__nr_max = 0

    def get_atelier(self):
        return self.__atelier

    def get_nr_min(self):
        return self.__nr_min

    def get_nr_max(self):
        return self.__nr_max



    def set_nr_min(self):
        pass
