class Serial:
    no_instances = 0

    def __init__(self, titlu, an_aparitie, eps):
        """
        Creeaza un nou serial cu titlul, anul aparitiei si numarul de episoade dat
        :param titlu: titlul serialului
        :type titlu: str
        :param an_aparitie: anul aparitiei serialului
        :type an_aparitie: int (1970-2021)
        :param eps: numarul de episoade din serial
        :type eps: int (>0)
        """
        self.__title = titlu
        self.__an_ap = an_aparitie
        self.__eps = eps
        Serial.no_instances += 1

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

    def __eq__(self, other):
        """
        Verifica egalitatea intre serialul curent si serialul other
        :param other:
        :type other: Serial
        :return: True daca serialele sunt egale (=au acelasi titlu si acelasi an de aparitie), False altfel
        :rtype: bool
        """
        if self.__title == other.getTitle() and self.__an_ap == other.getAnAparitie():
            return True
        return False

    # https://www.tutorialsteacher.com/python/magic-methods-in-python
    # puteti sa cititi aici pe link-ul de mai sus ce metode
    # se mai pot suprascrie pentru o clasa in afara de __eq__ si __str__

    def __str__(self):
        return "Titlu serial: " + self.__title + '; An aparitie: ' + str(self.__an_ap) + '; Nr. episoade: ' + str(
            self.__eps)

    @staticmethod
    def getNumberOfShowObjects():
        return Serial.no_instances


def test_create_serial():
    show1 = Serial('See', 2019, 12)
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
    show1 = Serial('See', 2019, 12)
    show2 = Serial('See', 2019, 10)

    assert (show1 == show2)

    show3 = Serial('See', 2018, 12)
    assert (show1 != show3)


test_create_serial()
test_equals_serial()
