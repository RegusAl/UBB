class Produs:

    def __init__(self, id, denumire, pret):
        self.__id = id
        self.__denumire = denumire
        self.__pret = pret

    def get_id(self):
        return self.__id

    def get_denumire(self):
        return self.__denumire

    def get_pret(self):
        return self.__pret

