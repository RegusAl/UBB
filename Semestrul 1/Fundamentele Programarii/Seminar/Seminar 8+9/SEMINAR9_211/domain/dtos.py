class ClientShowRating:
    def __init__(self, id_client, id_serial, no_stars):
        # fields: nume client, nume serial, no. stars
        self.__client_id = id_client
        self.__show_id = id_serial
        self.__nume_client = None
        self.__nume_serial = None
        self.__no_stars = no_stars

    def getClientId(self):
        return self.__client_id

    def getShowId(self):
        return self.__show_id

    def getNumeClient(self):
        return self.__nume_client

    def getTitluSerial(self):
        return self.__nume_serial

    def getNoStars(self):
        return self.__no_stars

    def setNumeClient(self, value):
        self.__nume_client = value

    def setTitluSerial(self, value):
        self.__nume_serial = value

    def setNoStars(self, value):
        self.__no_stars = value
