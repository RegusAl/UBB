from domeniu.inchiriere import Inchiriere
from erori.repo_error import RepoError

class RepoInchiriere:

    def __init__(self):
        self.__inchirieri = []
        # Inchiriere(1, 2),
        # Inchiriere(3, 2),
        # Inchiriere(3, 1),
        # Inchiriere(4, 4),
        # Inchiriere(2, 3),
        # Inchiriere(1, 6),
        # Inchiriere(2, 5),
        # Inchiriere(2, 2),
        # Inchiriere(8, 1),
        # Inchiriere(8, 7),
        # Inchiriere(2, 9)

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

class RepoInchiriereFile():

    def __init__(self, filename):
        self.__filename = filename

    def __load_from_file(self):
        '''
        Luam inchirierile din fisier
        (id_client, id_film)
        :return: lista de inchiriere
        '''
        try:
            f = open(self.__filename, 'r')
        except IOError:
            return
        lines = f.readlines()
        lista_inchiriere = []
        for line in lines:
            id_client, id_film = [token.strip() for token in line.split(';')]
            id_client = int(id_client)
            id_film = int(id_film)

            inchiriere = Inchiriere(id_client, id_film)
            lista_inchiriere.append(inchiriere)
        f.close()
        return lista_inchiriere

    def __save_from_file(self, lista_inchiriere):
        '''
        Salveaza lista de inchiriere in fisier
        :param lista_inchiriere: lista pe care o salveaza in fisier
        :return: -
        '''
        with open(self.__filename, 'w') as f:
            for inchiriere in lista_inchiriere:
                inchiriere_strings = str(inchiriere.get_client()) + ';' + str(inchiriere.get_film()) + '\n'
                f.write(inchiriere_strings)

    def adauga_inchiriere(self, inchiriere):
        '''
        Adauga o inchiriere in inchirieri
        :param inchiriere: inchirierea
        :type: Inchiriere
        :return: -
        '''
        for el in self.__load_from_file():
            if el.get_client() == inchiriere.get_client() and el.get_film() == inchiriere.get_film():
                raise RepoError("Inchirierea exista deja!")
        self.__save_from_file(inchiriere)

    def afisare(self):
        '''
        Returneaza lista de inchirieri din fisier
        :return: lista de inchirieri
        '''
        return self.__load_from_file()

    def stergere_film_dupa_id(self, id):
        lista_inchirieri = []
        for el in self.__load_from_file():
            if el.get_film() != id:
                lista_inchirieri.append(el)
        self.__save_from_file(lista_inchirieri)

    def stergere_client_dupa_id(self, id):
        lista_inchirieri = []
        for el in self.__load_from_file():
            if el.get_client() != id:
                lista_inchirieri.append(el)
        self.__save_from_file(lista_inchirieri)

    def returnare(self, id_client, id_film):
        lista_inchirieri = []
        for el in self.__load_from_file():
            if el.get_client() != id_client or el.get_film() != id_film:
                lista_inchirieri.append(el)
        self.__save_from_file(lista_inchirieri)


