import random
from domeniu.clienti import Client
from erori.repo_error import RepoError
from services.random_utils import random_string

class ServiceClienti:

    def __init__(self, validator_clienti, repo_clienti, repo_inchiriere):
        self.__validator_clienti = validator_clienti
        self.__repo_clienti = repo_clienti
        self.__repo_inchiriere = repo_inchiriere

    def adauga_client(self, id_client, nume_client, cnp_client):
        '''
        Adauga un client
        :param: id_client: id-ul clientului
        :type: int
        :param nume_client: numele clientului
        :type: string
        :param cnp_client: cnp-ul clientului
        :type: int
        :return: - ; apelam functii din Repo si Validator
        :raises: Error daca clientul are date invalide
        '''
        client = Client(id_client, nume_client, cnp_client)
        self.__validator_clienti.valideaza(client)
        self.__repo_clienti.adauga_client(client)
        return client

    def afisare_clienti(self):
        '''
        Afiseaza clientii
        :return: lista de clienti
        :rtype: lista de obiecte
        '''
        return self.__repo_clienti.get_all()

    def sterge_client_dupa_id(self, id_client):
        '''
        Sterge film in functie de id-ul primit prin parametru
        :param: id_film: id-ul filmului
        :type: int
        :return: -
        '''
        client = self.cauta_client_dupa_id(id_client)
        self.__repo_clienti.stergere_client(id_client)
        self.__repo_inchiriere.stergere_client_dupa_id(id_client)
        return client

    def cauta_client_dupa_id(self, id_client):
        '''
        Cauta clientul dupa id-ul primit prin parametru
        :param id_client: id-ul clientului
        :type: int
        :return: returneaza clientul
        :rtype RepoError
        '''
        lista = self.__repo_clienti.get_all()
        for el in lista:
            if el.get_id_client() == id_client:
                    return el
        raise RepoError("Client inexistent!")

    def clienti_random(self, nr):
        '''
        Functia adauga un numar random de clienti
        :param nr: random
        '''
        for index in range(nr):
            try:
                client = Client(random.randint(1, 100), random_string(5)+' '+random_string(10), random.randint(1000000000000, 9999999999999))
                self.__validator_clienti.valideaza(client)
                self.__repo_clienti.adauga_client(client)
            except RepoError:
                continue
