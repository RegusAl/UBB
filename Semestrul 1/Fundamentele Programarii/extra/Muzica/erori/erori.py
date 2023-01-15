class Erori(Exception):
    pass

class ValidError(Erori):

    def __init__(self, exception):
        self.__exception = exception

    def get_mesaj(self):
        return self.__exception

    def __str__(self):
        return "Eroare: \n" + self.get_mesaj()

class Validator():

    def __init__(self):
        pass

    def validator_melodie(self, melodie):
        erori = ""
        if melodie.get_titlu() == "":
            erori += "Campul pentru titlu este vid! \n"
        if melodie.get_artist() == "":
            erori += "Campul pentru artist este vid! \n"
        if melodie.get_gen() not in ["Rock", "Jazz", "Pop", "Altele"]:
            erori += "Gen invalid! Genul trebuie sa fie una dintre: Rock, Pop, Jazz, Altele\n"
        if melodie.get_durata() <= 0:
            erori += "Durata trebuie sa fie un numar pozitiv"
        if len(erori) > 0:
            raise ValidError(erori)