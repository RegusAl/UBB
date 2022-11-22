class Inchiriere:

    def __init__(self, id_client, id_film):
        self.__id_client = id_client
        self.__id_film = id_film

    def get_client(self):
        return self.__id_client

    def get_film(self):
        return self.__id_film

