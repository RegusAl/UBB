import random
from domeniu.filme import Film
from erori.repo_error import RepoError
from services.random_utils import random_string

class ServiceFilme:

    def __init__(self, validator_filme, repo_filme, repo_inchiriere):
        self.__validator_filme = validator_filme
        self.__repo_filme = repo_filme
        self.__repo_inchiriere = repo_inchiriere

    def adauga_film(self, id_film, nume_film, gen_film):
        '''
        Adauga un film
        :param: id_film: id-ul filmului
        :type: int
        :param nume_film: numele filmului
        :type: string
        :param gen_film: genul filmului
        :type: string
        :return: - ; apelam functii din Repo si Validator
        :raises: Error daca filmul are date invalide
        '''
        film = Film(id_film, nume_film, gen_film)
        self.__validator_filme.valideaza(film)
        self.__repo_filme.adauga_film(film)
        return film

    def afisare_filme(self):
        '''
        Afiseaza filmele
        :return: lista de filme
        :rtype: lista de obiecte
        '''
        return self.__repo_filme.get_all()

    def sterge_film_dupa_id(self, id_film):
        '''
        Sterge film in functie de id-ul primit prin parametru
        :param: id_film: id-ul filmului
        :type: int
        :return: -
        '''
        film = self.cauta_film_dupa_id(id_film)
        self.__repo_filme.stergere_film(id_film)
        self.__repo_inchiriere.stergere_film_dupa_id(id_film)
        return film

    def cauta_film_dupa_id(self, id_film):
        '''
        Cauta un film in functie de id-ul transmis prin parametru
        :param id_film: int
        :return: filmul cu id-ul cautat
        '''
        lista = self.__repo_filme.get_all()
        for el in lista:
            if el.get_id_film() == id_film:
                return el
        raise RepoError("Film inexistent!")

    def filme_random(self, nr):
        '''
        Functia adauga un numar random de filme
        :param nr: random
        '''
        for index in range(nr):
            try:
                film = Film(random.randint(1, 100), random_string(10), random_string(5))
                self.__validator_filme.valideaza(film)
                self.__repo_filme.adauga_film(film)
            except RepoError:
                continue

