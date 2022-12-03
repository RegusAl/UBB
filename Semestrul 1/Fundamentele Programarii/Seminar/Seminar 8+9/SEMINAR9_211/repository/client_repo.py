from domain.entities import Client
from exceptions.exceptions import CorruptedFileException, DuplicateIDException, ClientNotFoundException


class ClientInMemoryRepo:
    def __init__(self):
        self.__clients = {}

    def find(self, id):
        """
        Cauta clientul cu id dat
        :param id: id dat
        :type id: str
        :return: clientul cu id dat, None daca nu exista client cu id dat
        :rtype: Client
        """
        if id in self.__clients:
            return self.__clients[id]
        return None

    def store(self, client):
        """
       Adauga un client in lista
       :param client: clientul care se adauga
       :type client: Client
       :return: -; lista de cliente se modifica prin adaugarea clientului dat
        :rtype:
        :raises: DuplicateIDException daca clientul exista deja
        """
        # verificare id duplicat
        if client.getId() in self.__clients:
            raise DuplicateIDException()

        self.__clients[client.getId()] = client

    def get_all(self):
        """
        Returneaza o lista cu toate client-urile existente
        :rtype: list of objects de tip Client
        """
        return list(self.__clients.values())

    def size(self):
        """
        Returneaza numarul de cliente din multime
        :return: numar cliente existente
        :rtype:int
        """
        return len(self.__clients)

    def delete(self, id):
        """
        Sterge client dupa id
        :param id: id-ul dat
        :type id: str
        :return: clientul sters
        :rtype: Client
        :raises: ClientNotFoundException daca id-ul nu exista
        """
        if id not in self.__clients:
            raise ClientNotFoundException()

        deleted_client = self.__clients[id]
        del self.__clients[id]
        return deleted_client

    def update(self, id, modified_client):
        """
        Modifica datele clientului cu id dat
        :param id: id dat
        :type id: str
        :param modified_client: clientul cu datele noi
        :type modified_client: Client
        :return: clientul modificat
        :rtype: Client
        :raises: ClientNotFoundException daca id-ul nu exista
        """

        if id not in self.__clients:
            raise ClientNotFoundException()

        old_client = self.__clients[id]
        self.__clients[id] = modified_client
        return modified_client

    def delete_all(self):
        self.__clients = {}


class ClientFileRepo:
    def __init__(self, filename):
        self.__filename = filename

    def __load_from_file(self):
        """
        Incarca datele din fisier
        :return: lista cu clientii din fisier
        :rtype: list of Clients
        """

        try:
            f = open(self.__filename, 'r')
            # f = io.open(self.__filename, mode='r', encoding='utf-8')
        except IOError:
            raise CorruptedFileException()

        clients = []
        lines = f.readlines()
        for line in lines:
            client_id, client_name, client_age = [token.strip() for token in line.split(';')]
            a = Client(client_id, client_name, int(client_age))
            clients.append(a)
        f.close()
        return clients

    def __save_to_file(self, client_list):
        """
        Salveaza in fisier clientii dati
        :param client_list: lista de clienti
        :type client_list: list of Clients
        :return: -
        :rtype: -
        """
        with open(self.__filename, 'w') as f:
            for client in client_list:
                client_string = str(client.getId()) + ';' + str(client.getNume()) + ';' + str(
                    client.getVarsta()) + '\n'
                f.write(client_string)

    def store(self, client):
        """
        Adauga client in lista
        :param client: clientul de adaugat
        :type client: Client
        :return: -; lista de clienti se modifica prin adaugarea clientului
        :rtype: -; clientul este adaugat
        :raises: DuplicateIDException daca exista deja clientul
        """
        all_clients = self.__load_from_file()
        if client in all_clients:
            raise DuplicateIDException()
        all_clients.append(client)
        self.__save_to_file(all_clients)

    def find(self, id):
        """
        Cauta clientul cu id dat
        :param id: id dat
        :type id: str
        :return: clientul cu id dat, None daca nu exista client cu id dat
        :rtype: Client
        """
        all_clients = self.__load_from_file()
        for client in all_clients:
            if client.getId() == id:
                return client
        return None

    def get_all(self):
        """
        Returneaza o lista cu toti clientii existenti
        :rtype: list of objects de tip Client
        """
        return self.__load_from_file()

    def size(self):
        """
        Returneaza numarul de clienti din multime
        :return: numar clienti existenti
        :rtype:int
        """
        return len(self.__load_from_file())

    def __find_index(self, all_clients, id):
        """
        Gaseste pozitia in lista all_clients a clientului cu id id
        :param all_clients: lista de clienti
        :type all_clients: list of Clients
        :param id: id-ul dat
        :type id: str
        :return: pozitia Clientului cu id id in lista data, -1 daca nu exista
        :rtype: int, >0, <len(all_clients)
        """
        index = -1
        for i in range(len(all_clients)):
            if all_clients[i].getId() == id:
                index = i
                break
        return index

    def delete(self, id):
        """
        Sterge client dupa id
        :param id: id-ul dat
        :type id: str
        :return: clientul sters
        :rtype: Client
        :raises: ClientNotFoundException daca id-ul nu exista
        """
        all_clients = self.__load_from_file()
        index = self.__find_index(all_clients, id)
        if index == -1:
            raise ClientNotFoundException()

        deleted_client = all_clients.pop(index)
        self.__save_to_file(all_clients)
        return deleted_client

    def update(self, id, modified_client):
        """
        Modifica datele clientului cu id dat
        :param id: id dat
        :type id: str
        :param modified_client: clientul cu datele noi
        :type modified_client: Client
        :return: clientul modificat
        :rtype: Client
        :raises: ClientNotFoundException daca nu exista client cu id dat
        """
        all_clients = self.__load_from_file()
        index = self.__find_index(all_clients, id)
        if index == -1:
            raise ClientNotFoundException()

        all_clients[index] = modified_client
        self.__save_to_file(all_clients)

        return modified_client

    def delete_all(self):
        self.__save_to_file([])


class ClientFileRepoInheritance(ClientInMemoryRepo):
    def __init__(self, filename):
        ClientInMemoryRepo.__init__(self)
        self.__filename = filename
        self.__load_from_file()

    def __load_from_file(self):
        try:
            f = open(self.__filename, 'r')
            # f = io.open(self.__filename, mode='r', encoding='utf-8')
        except IOError:
            raise CorruptedFileException()

        lines = f.readlines()
        for line in lines:
            client_id, client_name, client_age = [token.strip() for token in line.split(';')]
            a = Client(client_id, client_name, client_age)
            ClientInMemoryRepo.store(self, a)
        f.close()

    def __save_to_file(self):
        client_list = ClientInMemoryRepo.get_all(self)
        with open(self.__filename, 'w') as f:
            for client in client_list:
                client_string = str(client.getId()) + ';' + str(client.getNume()) + ';' + str(
                    client.getVarsta()) + '\n'
                f.write(client_string)

    def store(self, client):
        ClientInMemoryRepo.store(self, client)
        self.__save_to_file()

    def update(self, id, new_client):
        updated_client = ClientInMemoryRepo.update(self, id, new_client)
        self.__save_to_file()
        return updated_client

    def delete(self, id):
        deleted_client = ClientInMemoryRepo.delete(self, id)
        self.__save_to_file()
        return deleted_client

    def get_all(self):
        return ClientInMemoryRepo.get_all(self)

    def size(self):
        return ClientInMemoryRepo.size(self)

    def delete_all(self):
        ClientInMemoryRepo.delete_all(self)
        self.__save_to_file()

    def find(self, id):
        return ClientInMemoryRepo.find(self, id)

# TO DO: add missing specifications
