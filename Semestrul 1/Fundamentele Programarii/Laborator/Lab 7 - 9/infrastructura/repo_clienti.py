from domeniu.clienti import Client
from erori.repo_error import RepoError

class RepoClienti:

    def __init__(self):

        # lista de liste
        self.__clienti = [
            # Client(1, "Mihai Ion", 5030724668945),
            # Client(2, "Alexandru Popescu", 6023115705789),
            # Client(3, "Mihaela Sandu", 3201343245673),
            # Client(4, "Mihai Eminescu", 1234115678901),
            # Client(5, "Ion Creanga", 5067812345234),
            # Client(6, "Andreea Georgeta", 1232145676543),
            # Client(7, "George Popa", 5786123453345),
            # Client(8, "Emilut Pilaf", 78547235879123)
        ]

    def adauga_client(self, client):
        '''
        Adauga un client in lista de clienti
        :param client: clientul ce trebuie adaugat
        :type client: Client
        :return: -; lista de clienti se modifica prin adaugarea clientului dat de utilizator
        '''
        for el in self.__clienti:
            if el.get_id_client() == client.get_id_client():
                raise RepoError("Client existent!")
        self.__clienti.append(client)

    def get_all(self):
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
            if el.get_id_client() != id:
                lista_clienti.append(el)
            if el.get_id_client() == id:
                ok = True
        if ok == False:
            raise RepoError("Client inexistent!")
        self.__clienti = lista_clienti.copy()

class RepoClientiFile:

        def __init__(self, filename):
            self.__filename = filename

        def __load_from_file(self):
            '''
            Luam clientii din fisier
            :return: -
            '''
            try:
                f = open(self.__filename, 'r')
            except IOError:
                return
            lines = f.readlines()
            clienti = []
            for line in lines:
                id_client, nume_client, cnp_client = [token.strip() for token in line.split(';')]
                id_client = int(id_client)
                cnp_client = int(cnp_client)

                client = Client(id_client, nume_client, cnp_client)
                clienti.append(client)
            f.close()
            return clienti

        def __save_from_file(self, clienti):
            '''
            Salvam clientii in fisier
            :param clienti: lista de clienti ce trebuie salvata in fisier
            :return: -
            '''
            with open(self.__filename, 'w') as f:
                for client in clienti:
                    clienti_strings = str(client.get_id_client()) + ';' + str(client.get_nume_client()) + ';' + str(client.get_cnp_client()) + '\n'
                    f.write(clienti_strings)

        def adauga_client(self, client):
            '''
            Adauga un client pe care il incarca in fisier
            :param client: clientul ce trebuie incarcat in fisier
            :return: -
            '''
            clienti = self.__load_from_file()
            if client in clienti:
                raise RepoError("Client existent!")
            clienti.append(client)
            self.__save_from_file(clienti)

        def get_all(self):
            '''
            Returneaza o lista cu toti clientii
            :rtype: lista
            '''
            return self.__load_from_file()

        def stergere_client(self, id_client):
            '''
            Sterge clientul in functie de id
            :param id_client: int
            :return: -; Copie in lista de client toti clientii, fara clientul cu id-ul dat de utilizator
            '''
            lista_clienti = []
            ok = False
            for el in self.__load_from_file():
                if el.get_id_client() != id_client:
                    lista_clienti.append(el)
                if el.get_id_client() == id_client:
                    ok = True
            if ok == False:
                raise RepoError("Client inexistent!")
            self.__save_from_file(lista_clienti)
