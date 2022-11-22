class Client:

    def __init__(self, id_client, nume_client, cnp_client):
        self.__id_client = id_client
        self.__nume_client = nume_client
        self.__cnp_client = cnp_client

    def set_nume(self, nume_client):
        self.__nume_client = nume_client

    def set_gen(self, gen_film):
        self.__gen_film = gen_film

    def __eq__(self, other):
        return self.__id_client == other.__id_client

    def get_id_client(self):
        return self.__id_client

    def get_nume_client(self):
        return self.__nume_client

    def get_cnp_client(self):
        return self.__cnp_client
