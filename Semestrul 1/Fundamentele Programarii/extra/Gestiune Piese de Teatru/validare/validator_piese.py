class ExceptionPiesa(Exception):
    pass

class RepoError(ExceptionPiesa):

    def __init__(self, exception):
        self.__exception = exception

    def get_mesaj(self):
        return self.__exception

    def __str__(self):
        return "Eroare: \n" + self.get_mesaj()

class ValidError(ExceptionPiesa):

    def __init__(self, exception):
        self.__exception = exception

    def get_mesaj(self):
        return self.__exception

    def __str__(self):
        return "Eroare: \n" + self.get_mesaj()

class Validator():

    def __init__(self):
        pass

    def validator_piesa(self, piesa):
        erori = ""
        if piesa.get_titlu() == "":
            erori += "Campul pentru titlu este vid! \n"
        if piesa.get_regizor() == "":
            erori += "Campul pentru regizor este vid! \n"
        if piesa.get_gen() not in ["Comedie", "Drama", "Satira", "Altele"]:
            erori += "Gen invalid! Genul trebuie sa fie una dintre: 'Comedie', 'Drama', 'Satira', 'Altele' \n"
        if piesa.get_durata() < 0:
            erori += "Durata piesei de teatru trebuie sa fie un numar pozitiv! \n"
        if len(erori) > 0:
            raise ValidError(erori)
