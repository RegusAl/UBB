class Client:

    def __init__(self, id_client, nume_client, cnp_client):
        self.__id_client = id_client
        self.__nume_client = nume_client
        self.__cnp_client = cnp_client

    def creare_client(self):
        client =  [self.__id_client, self.__nume_client, self.__cnp_client]
        # client = {'id': self.__id_client, 'nume': self.__nume_client, 'cnp': self.__cnp_client}
        return client

def get_id_client(client):
    return client[0]

def get_nume_client(client):
    return client[1]

def get_cnp_client(client):
    return client[2]
