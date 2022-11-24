from domeniu.inchiriere import Inchiriere
from erori.repo_error import RepoError

class RepoInchiriere:

    def __init__(self):
        self.__inchirieri = [
            Inchiriere(1, 2),
            Inchiriere(3, 2),
            Inchiriere(3, 1),
            Inchiriere(4, 4),
            Inchiriere(2, 3),
            Inchiriere(1, 6),
            Inchiriere(2, 5),
            Inchiriere(2, 2),
            Inchiriere(8, 1),
            Inchiriere(8, 7)
        ]

    def adauga_inchiriere(self, inchiriere):
        '''
        Adauga o inchiriere in inchirieri
        :param inchiriere: inchirierea
        :type: Inchiriere
        :return: -
        '''
        for el in self.__inchirieri:
            if el.get_client() == inchiriere.get_client() and el.get_film() == inchiriere.get_film():
                raise RepoError("Inchirierea exista deja!")
        self.__inchirieri.append(inchiriere)

    def afisare(self):
        '''
        Returneaza lista de inchirieri
        :return: lista de inchirieri
        '''
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

