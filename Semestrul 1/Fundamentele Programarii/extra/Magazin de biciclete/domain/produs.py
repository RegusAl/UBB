class Produs:

    def __init__(self, id_bicicleta, tip, pret):
        self.__id_bicicleta = id_bicicleta
        self.__tip = tip
        self.__pret = pret

    def get_id_bicicleta(self):
        return self.__id_bicicleta

    def get_tip(self):
        return self.__tip

    def get_pret(self):
        return self.__pret