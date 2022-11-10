class InMemoryRepository:
    """
        Clasa creata cu responsabilitatea de a gestiona
        multimea de seriale (i.e. sa ofere un depozit persistent pentru obiecte
        de tip serial)

        Detaliere: seminar 7
    """
    def __init__(self):
        # shows - multimea de seriale pe care o gestionam
        # poate fi si dictionar, este la latitudinea noastra cum stocam datele
        # e.g. stocare in dict cu un camp in plus id_serial (dar se poate lua titlu ca si cheie
        # de ex, daca am sti ca e unic):
        # {idSerial1: Serial1, idSerial2: Serial2}
        # vs. [serial1, serial2]
        self.__shows = []


    def store(self, show):
        """
        Adauga un serial in lista
        :param show: serialul care se adauga
        :type show: Serial
        :return: -; lista de seriale se modifica prin adaugarea serialului dat
        :rtype:
        """
        self.__shows.append(show)

    def get_all_shows(self):
        """
        Returneaza o lista cu toate show-urile existente
        :rtype: list of objects de tip Serial
        """
        return self.__shows

def test_store():
    pass
def test_get_all_shows():
    pass