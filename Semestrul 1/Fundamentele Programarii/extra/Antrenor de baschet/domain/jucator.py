class Jucator:

    def __init__(self, nume, prenume, inaltime, post):
        self.__nume = nume
        self.__prenume = prenume
        self.__inaltime = inaltime
        self.__post = post

    def get_nume(self):
        return self.__nume

    def get_prenume(self):
        return self.__prenume

    def get_inaltime(self):
        return self.__inaltime

    def get_post(self):
        return self.__post

    def set_inaltime(self, inaltime):
        self.__inaltime = inaltime


