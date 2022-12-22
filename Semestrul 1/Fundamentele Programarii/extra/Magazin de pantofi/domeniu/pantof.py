class Pantof:

    def __init__(self, id, denumire, marime, numar_perechi, pret, personalizare):
        self.__id = id
        self.__denumire = denumire
        self.__marime = marime
        self.__numar_perechi = numar_perechi
        self.__pret = pret
        self.__personalizare = personalizare

    def get_id(self):
        return self.__id

    def get_denumire(self):
        return self.__denumire

    def get_marime(self):
        return self.__marime

    def get_numar_perechi(self):
        return self.__numar_perechi

    def get_pret(self):
        return self.__pret

    def get_personalizare(self):
        return self.__personalizare

    def set_numar_perechi(self, numar_nou):
        self.__numar_perechi = numar_nou