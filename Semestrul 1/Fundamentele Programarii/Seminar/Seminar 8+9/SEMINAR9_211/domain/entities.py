class Serial:
    def __init__(self, id, titlu, an_aparitie, eps):
        """
        Creeaza un nou serial cu titlul, anul aparitiei si numarul de episoade dat
        :param titlu: titlul serialului
        :type titlu: str
        :param an_aparitie: anul aparitiei serialului
        :type an_aparitie: int (1970-2021)
        :param eps: numarul de episoade din serial
        :type eps: int (>0)
        """
        self.__id = id
        self.__title = titlu
        self.__an_ap = an_aparitie
        self.__eps = eps

    def getId(self):
        return self.__id

    def getTitle(self):
        return self.__title

    def getAnAparitie(self):
        return self.__an_ap

    def getEpisoade(self):
        return self.__eps

    def setTitle(self, value):
        self.__title = value

    def setAnAparitie(self, value):
        self.__an_ap = value

    def setEpisoade(self, value):
        self.__eps = value

    def setId(self, value):
        self.__id = value

    def __eq__(self, other):
        """
        Verifica egalitatea intre serialul curent si serialul other
        :param other:
        :type other: Serial
        :return: True daca serialele sunt egale (au acelasi id), False altfel
        :rtype: bool
        """
        if self.__id == other.getId():
            return True
        return False

    def __str__(self):
        return "ID:" + str(self.getId()) + "; Titlu serial: " + self.__title + '; An aparitie: ' + str(
            self.__an_ap) + '; Nr. episoade: ' + str(
            self.__eps)



class Client:
    def __init__(self, id, nume, varsta):
        self.__id = id
        self.__nume = nume
        self.__varsta = varsta

    def getId(self):
        return self.__id

    def getNume(self):
        return self.__nume

    def getVarsta(self):
        return self.__varsta

    def setId(self, value):
        self.__id = value

    def setNume(self, value):
        self.__nume = value

    def setVarsta(self, value):
        self.__varsta = value

    def __eq__(self, other):
        if self.__id == other.__id:
            return True
        return False

    def __str__(self):
        return 'ID: ' + str(self.__id) + '; Nume: ' + str(self.__nume) + '; Varsta: ' + str(self.__varsta)


class Rating:
    def __init__(self, serial_id, client_id, no_stars):
        self.__serial_id = serial_id
        self.__client_id = client_id
        self.__no_stars = no_stars

    def getSerialId(self):
        return self.__serial_id

    def getClientId(self):
        return self.__client_id

    def getNoStars(self):
        return self.__no_stars

    def setSerialId(self, value):
        self.__serial_id = value

    def setClientId(self, value):
        self.__client_id = value

    def setNoStars(self, value):
        self.__no_stars = value

    def __eq__(self, other):
        if self.__serial_id == other.__serial_id and self.__client_id == other.__client_id:
            return True
        return False

    def __str__(self):
        return 'Serial: [' + str(self.__serial_id) + ']; ' + \
               'Client: [' + str(self.__client_id) + '];''Rating: ' + str(self.__no_stars)

