class Client:

    def __init__(self, id_client, nume_client, cnp_client):
        self.__id_client = id_client
        self.__nume_client = nume_client
        self.__cnp_client = cnp_client

    def creare_client(self):
        film =  [self.__id_client, self.__nume_client, self.__cnp_client]
        return film