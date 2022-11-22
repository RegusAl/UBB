from domeniu.inchiriere import Inchiriere


class RepoInchiriere:

    def __init__(self):
        self.__inchirieri = [
            Inchiriere(1, 2),
            Inchiriere(3, 2)
        ]

    def adauga_inchiriere(self, inchiriere):
        self.__inchirieri.append(inchiriere)

    def afisare(self):
        return self.__inchirieri

    def stergere_film_dupa_id(self, id):
        lista_inchirieri = []
        for el in self.__inchirieri:
            if el.get_film() != id:
                lista_inchirieri.append(el)
        self.__inchirieri = lista_inchirieri.copy()

    def stergere_client_dupa_id(self, id):
        lista_inchirieri = []
        for el in self.__inchirieri:
            if el.get_client() != id:
                lista_inchirieri.append(el)
        self.__inchirieri = lista_inchirieri.copy()

    def returnare(self, id_client, id_film):
        lista_inchirieri = []
        for el in self.__inchirieri:
            if el.get_client() != id_client or el.get_film() != id_film:
                lista_inchirieri.append(el)
        self.__inchirieri = lista_inchirieri.copy()

