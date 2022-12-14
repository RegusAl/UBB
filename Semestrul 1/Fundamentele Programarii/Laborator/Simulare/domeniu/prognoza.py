
class PrognozaMeteo:

    def __init__(self, id, data, locatia, prognoza, temp_minima, temp_maxima):
        self.__id = id
        self.__data = data
        self.__locatia = locatia
        self.__prognoza = prognoza
        self.__temp_minima = temp_minima
        self.__temp_maxima = temp_maxima

    def get_id(self):
        return self.__id

    def get_data(self):
        return self.__data

    def get_locatia(self):
        return self.__locatia

    def get_prognoza(self):
        return self.__prognoza

    def get_temp_minima(self):
        return self.__temp_minima

    def get_temp_maxima(self):
        return self.__temp_maxima
