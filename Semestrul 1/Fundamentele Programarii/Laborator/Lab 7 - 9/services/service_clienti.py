from domeniu.clienti import Client
class ServiceClienti:

    def __init__(self, validator_clienti, repo_clienti):
        self.__validator_clienti = validator_clienti
        self.__repo_clienti = repo_clienti

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
        client = Client(id_client, nume_client, cnp_client).creare_client()
        self.__validator_clienti.valideaza(client)
        self.__repo_clienti.adauga_client(client)

    def afisare_clienti(self):
        '''
        Afiseaza clientii
        :return: lista de clienti
        :rtype: lista de obiecte
        '''
        return self.__repo_clienti.afisare_clienti()

    def sterge_client_dupa_id(self, id_client):
        '''
        Sterge film in functie de id-ul primit prin parametru
        :param: id_film: id-ul filmului
        :type: int
        :return: -
        '''
        self.__repo_clienti.stergere_client(id_client)