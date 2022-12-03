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


def test_create_serial():
    show1 = Serial('SF123', 'See', 2019, 12)
    assert (show1.getTitle() == 'See')
    assert (show1.getAnAparitie() == 2019)
    assert (show1.getEpisoade() == 12)

    show1.setTitle('See (2021)')
    show1.setAnAparitie(2021)
    show1.setEpisoade(1)

    assert (show1.getTitle() == 'See (2021)')
    assert (show1.getAnAparitie() == 2021)
    assert (show1.getEpisoade() == 1)


def test_equals_serial():
    show1 = Serial('23', 'See', 2019, 12)
    show2 = Serial('23', 'See', 2019, 10)

    assert (show1 == show2)

    show3 = Serial('SF1', 'See', 2018, 12)
    assert (show1 != show3)


test_create_serial()
test_equals_serial()


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
    def __init__(self, serial, client, no_stars):
        self.__serial = serial
        self.__client = client
        self.__no_stars = no_stars

    def getSerial(self):
        return self.__serial

    def getClient(self):
        return self.__client

    def getNoStars(self):
        return self.__no_stars

    def setSerial(self, value):
        self.__serial = value

    def setClient(self, value):
        self.__client = value

    def setNoStars(self, value):
        self.__no_stars = value

    def __eq__(self, other):
        if self.__serial == other.__serial and self.__client == other.__client:
            return True
        return False

    def __str__(self):
        return 'Serial: [' + str(self.__serial.getTitle()) + '; ' + str(self.__serial.getAnAparitie()) + ']' + \
               'Client: [' + str(self.__client.getNume()) + ';' + str(
            self.__client.getVarsta()) + ']' + 'Rating: ' + str(
            self.__no_stars)


def test_create_rating():
    show = Serial('SF123', 'See', 2019, 12)
    client = Client('1', 'Maria', 26)

    rating = Rating(show, client, 4.1)

    assert (rating.getSerial() == show)
    assert (rating.getClient() == client)
    assert (rating.getNoStars() == 4.1)


def test_equal_rating():
    show = Serial('SF123', 'See', 2019, 12)
    client = Client('1', 'Maria', 26)

    rating1 = Rating(show, client, 4.1)
    rating2 = Rating(show, client, 4.5)
    assert (rating1 == rating2)

    show2 = Serial('D564', 'Ozark', 2016, 48)
    rating3 = Rating(show2, client, 3)
    assert (rating3 != rating2)
