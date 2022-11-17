from domeniu.clienti import get_id_client
from erori.repo_error import RepoError
class RepoClienti:

    def __init__(self):

        # lista de liste
        self.__clienti = [
            [1, "Mihai Ion", 5030724668945],
            [2, "Alexandru Popescu", 6023115705789],
            [3, "Mihaela Sandu", 3201343245673],
            [4, "Mihai Eminescu", 1234115678901]
        ]

        # lista de dictionare
        # self.__clienti = [
        #     {'id': 1, 'nume': "Mihai Ion", 'cnp': 5030724668945},
        #     {'id': 2, 'nume': "Alexandru Popescu", 'cnp': 6023115705789},
        #     {'id': 3, 'nume': "Mihaela Sandu", 'cnp': 3201343245673},
        #     {'id': 4, 'nume': "Mihai Eminescu", 'cnp': 1234115678901}
        # ]

    def adauga_client(self, client):
        '''
        Adauga un client in lista de clienti
        :param client: clientul ce trebuie adaugat
        :type client: Client
        :return: -; lista de clienti se modifica prin adaugarea clientului dat de utilizator
        '''
        for el in self.__clienti:
            if get_id_client(el) == get_id_client(client):
                raise RepoError("Client existent!")
        self.__clienti.append(client)

    def afisare_clienti(self):
        '''
        Returneaza lista de clienti
        :return: lista de clienti
        :rtype: lista
        '''
        return self.__clienti

    def stergere_client(self, id):
        '''
        Sterge clientul in functie de id
        :param id: int
        :return: -; Copie in lista de client toti clientii, fara clientul cu id-ul dat de utilizator
        '''
        lista_clienti = []
        ok = False
        for el in self.__clienti:
            if get_id_client(el) != id:
                lista_clienti.append(el)
            if get_id_client(el) == id:
                ok = True
        if ok == False:
            raise RepoError("Client inexistent!")
        self.__clienti = lista_clienti.copy()