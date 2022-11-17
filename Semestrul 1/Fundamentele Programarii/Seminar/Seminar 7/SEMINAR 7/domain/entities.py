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
