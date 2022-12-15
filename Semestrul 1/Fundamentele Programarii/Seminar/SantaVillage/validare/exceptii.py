class ExceptionLocatie(Exception):
    pass

class ExceptionCautare(ExceptionLocatie):

    def __init__(self, mesaj):
        self.__mesaj = mesaj

    def get_mesaj(self):
        return self.__mesaj

    def __str__(self):
        return "exceptie cautare: " + self.get_mesaj()

class ExceptionProdusNegasit(ExceptionCautare):
    def __init__(self):
        ExceptionCautare.__init__(self, "Nu s-a gasit atelier cu acest tip de produs!")

class ExceptionPutiniSpiridusi(ExceptionCautare):
    def __init__(self, produs):
        ExceptionCautare.__init__(self, f"Nu s-a gasit un atelier numarul acesta de spiridusi pentru a face {produs}!")

