class Contact:

    def __init__(self, id, nume, nrTelefon, grup):
        self.__id = id
        self.__nume = nume
        self.__nrTelefon = nrTelefon
        self.__grup = grup

    def get_id(self):
        return self.__id

    def get_nume(self):
        return self.__nume

    def get_nrTelefon(self):
        return self.__nrTelefon

    def get_grup(self):
        return self.__grup

class Validator:

    def __init__(self):
        pass
    def validate(self, contact):
        erori = []
        if contact.get_nume() == '':
            erori.append("".join("Numele nu poate fi vid! "))
        if contact.get_nrTelefon() == '':
            erori.append("".join("Numarul de telefon nu poate fi vid"))
        if contact.get_grup() not in ["Prieteni", "Familie", "Job", "Altele"]:
            erori.append("".join("Grupui trebuie sa fie una dintre: Prieteni, Familie, Job, Altele "))
        if len(erori) > 0:
            raise ValueError(erori)

