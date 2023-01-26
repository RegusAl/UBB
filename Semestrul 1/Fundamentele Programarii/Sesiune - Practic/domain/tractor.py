class Tractor:

    def __init__(self, id, denumire, pret, model, data):
        self.__id = id
        self.__denumire = denumire
        self.__pret = pret
        self.__model = model
        self.__data = data

    def get_id(self):
        return self.__id

    def get_denumire(self):
        return self.__denumire

    def get_pret(self):
        return self.__pret

    def get_model(self):
        return self.__model

    def get_data(self):
        return self.__data

    def set_denumire(self):
        self.__denumire = "*" + self.__denumire