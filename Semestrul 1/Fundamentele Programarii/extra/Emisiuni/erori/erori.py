class EmisiuneException(Exception):
    pass

class RepoError(EmisiuneException):

    def __init__(self, exception):
        self.__exception = exception

    def get_mesaj(self):
        return self.__exception

    def __str__(self):
        return "Eroare: " + self.get_mesaj() + '\n'

class BlocatError(EmisiuneException):

    def __init__(self, exception):
        self.__exception = exception

    def get_mesaj(self):
        return self.__exception

    def __str__(self):
        return "Eroare: " + self.get_mesaj() + '\n'