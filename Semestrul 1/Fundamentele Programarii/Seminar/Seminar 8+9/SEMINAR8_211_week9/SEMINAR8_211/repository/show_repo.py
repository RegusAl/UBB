from domain.entities import Serial
from exceptions.exceptions import DuplicateIDException, ShowNotFoundException


class ShowInMemoryRepo:
    def __init__(self):
        # {idSerial1: Serial1, idSerial2: Serial2}
        self.__shows = {}

    def find(self, id):
        """
        Cauta serialul cu id dat
        :param id: id dat
        :type id: str
        :return: serialul cu id dat, None daca nu exista serial cu id dat
        :rtype: Serial
        """
        if id in self.__shows:
            return self.__shows[id]
        return None

    def store(self, show):
        """
       Adauga un serial in lista
       :param show: serialul care se adauga
       :type show: Serial
       :return: -; lista de seriale se modifica prin adaugarea serialului dat
        :rtype:
        :raises: DuplicateIDException daca serialul exista deja
        """
        # verificare id duplicat
        if show.getId() in self.__shows:
            raise DuplicateIDException()

        self.__shows[show.getId()] = show

    def get_all(self):
        """
        Returneaza o lista cu toate show-urile existente
        :rtype: list of objects de tip Serial
        """
        return list(self.__shows.values())

    def size(self):
        """
        Returneaza numarul de seriale din multime
        :return: numar seriale existente
        :rtype:int
        """
        return len(self.__shows)

    def delete(self, id):
        """
        Sterge serial dupa id
        :param id: id-ul dat
        :type id: str
        :return: serialul sters
        :rtype: Serial
        :raises: ShowNotFoundException daca id-ul nu exista
        """
        if id not in self.__shows:
            raise ShowNotFoundException()

        deleted_show = self.__shows[id]
        del self.__shows[id]
        return deleted_show

    def update(self, id, modified_show):
        """
        Modifica datele serialului cu id dat
        :param id: id dat
        :type id: str
        :param modified_show: show-ul cu datele noi
        :type modified_show: Serial
        :return: show-ul modificat
        :rtype: Serial
        """

        if id not in self.__shows:
            raise ShowNotFoundException()

        old_show = self.__shows[id]
        self.__shows[id] = modified_show
        return modified_show


def setup_test_repo():
    serial1 = Serial('C1001', 'Superstore', 2019, 98)
    serial2 = Serial('F1001', 'Arrow', 2012, 170)
    serial3 = Serial('C1002', 'Modern Family', 2009, 250)
    serial4 = Serial('D1001', 'Squid Game', 2021, 9)
    serial5 = Serial('F1002', 'See', 2019, 16)
    serial6 = Serial('D1854', 'Grey\'s Anatomy', 2005, 384)
    serial7 = Serial('F2638', 'The Magicians', 2015, 65)
    serial8 = Serial('D1211', 'Atypical', 2017, 38)
    serial9 = Serial('D1372', 'ER', 1994, 331)
    serial10 = Serial('SF1643', 'The X-Files', 1993, 218)

    test_repo = ShowInMemoryRepo()
    test_repo.store(serial1)
    test_repo.store(serial2)
    test_repo.store(serial3)
    test_repo.store(serial4)
    test_repo.store(serial5)
    test_repo.store(serial6)
    test_repo.store(serial7)
    test_repo.store(serial8)
    test_repo.store(serial9)
    test_repo.store(serial10)
    return test_repo


def test_find():
    test_repo = setup_test_repo()

    p = test_repo.find('SF1643')
    assert (p.getTitle() == 'The X-Files')
    assert (p.getAnAparitie() == 1993)
    assert (p.getEpisoade() == 218)

    p1 = test_repo.find('SF1645')
    assert (p1 is None)


def test_size():
    test_repo1 = setup_test_repo()
    assert (test_repo1.size() == 10)
    test_repo1.delete('C1001')
    test_repo1.delete('F2638')

    assert (test_repo1.size() == 8)

    test_repo1.store(Serial('HD2384', 'The Crown', 2016, 41))
    assert (test_repo1.size() == 9)
    test_repo1.update('HD2384', Serial('HD2384', 'The Crown', 2016, 40))
    assert (test_repo1.size() == 9)


def test_get_all():
    test_repo1 = setup_test_repo()
    crt_shows = test_repo1.get_all()
    assert (type(crt_shows) == list)
    assert (len(crt_shows) == 10)

    test_repo1.delete('C1001')
    test_repo1.delete('F2638')

    crt_shows = test_repo1.get_all()
    assert (len(crt_shows) == 8)

    test_repo1.store(Serial('HD2384', 'The Crown', 2016, 41))
    assert (test_repo1.size() == 9)

    # not a good test if we don't know if the show is stored on the last position or not
    # e.g. what is returned from get_all for RepoDict?
    assert (test_repo1.get_all()[-1].getTitle() == 'The Crown')
    assert (test_repo1.get_all()[-1].getAnAparitie() == 2016)

    test_repo1.update('HD2384', Serial('HD2384', 'The Crown', 2016, 40))

    # is it always the case that the updated show keeps its position?
    # e.g. implement update as delete(old_show) + insert(new_show)

    assert (test_repo1.get_all()[-1].getEpisoade() == 40)
    assert (test_repo1.size() == 9)


def test_store():
    test_repo = ShowInMemoryRepo()
    show1 = Serial('23', 'See', 2019, 12)
    test_repo.store(show1)

    assert (test_repo.size() == 1)
    show2 = Serial('234', 'Kim\'s Convenience', 2016, 67)
    test_repo.store(show2)
    assert (test_repo.size() == 2)

    try:
        # duplicate id
        test_repo.store(show2)
        assert False
    except DuplicateIDException:
        assert True


def test_delete():
    test_repo = ShowInMemoryRepo()
    show1 = Serial('23', 'See', 2019, 12)
    test_repo.store(show1)
    show2 = Serial('234', 'Kim\'s Convenience', 2016, 67)
    test_repo.store(show2)

    deleted_show = test_repo.delete('234')
    assert (deleted_show.getTitle() == 'Kim\'s Convenience')
    assert (test_repo.size() == 1)

    show_left = test_repo.find('23')
    assert (show_left.getTitle() == 'See')

    try:
        test_repo.delete('wrongid')
        assert False
    except ShowNotFoundException:
        assert True


def test_update():
    test_repo = ShowInMemoryRepo()
    show1 = Serial('23', 'See', 2019, 12)
    test_repo.store(show1)
    show2 = Serial('234', 'Kim\'s Convenience', 2016, 67)
    test_repo.store(show2)
    show3 = Serial('234', 'Kim', 2016, 78)

    modified_show = test_repo.update('234', show3)
    assert (modified_show.getTitle() == 'Kim')
    assert (modified_show.getAnAparitie() == 2016)
    assert (modified_show.getEpisoade() == 78)

    try:
        test_repo.update('243545', Serial('234', 'Kim', 2016, 78))
        assert False
    except ShowNotFoundException:
        assert True


class ShowFileRepo:
    def __init__(self, filename):
        self.__filename = filename

    def __load_from_file(self):
        """
        Incarca datele din fisier
        :return: lista de seriale din fisier
        :rtype: list of Serial objects
        :raises: ...
        """
        try:
            f = open(self.__filename, 'r')
            # f = io.open(self.__filename, mode='r', encoding='utf-8')
        except IOError:
            return

        lines = f.readlines()
        # lines: ['C1001;Superstore;2019;98', 'F1001; Arrow;2012;170',...]
        all_shows = []
        for line in lines:
            show_id, show_name, show_year, show_eps = [token.strip() for token in line.split(';')]
            show_year = int(show_year)
            show_eps = int(show_eps)

            s = Serial(show_id, show_name, show_year, show_eps)
            all_shows.append(s)

        f.close()
        return all_shows

    def __save_to_file(self, all_shows):
        """
        Salveaza serialele in fisier
        """
        with open(self.__filename, 'w') as f:
            for show in all_shows:
                show_string = str(show.getId()) + ';' + str(show.getTitle()) + ';' + str(
                    show.getAnAparitie()) + ';' + str(show.getEpisoade()) + '\n'
                f.write(show_string)

    def find(self, id):
        """
        Cauta serialul cu id dat
        :param id: id dat
        :type id: str
        :return: serialul cu id dat, None daca nu exista serial cu id dat
        :rtype: Serial
        """
        all_shows = self.__load_from_file()
        for show in all_shows:
            if show.getId() == id:
                return show
        return None

    def store(self, show):
        """
       Adauga un serial in lista
       :param show: serialul care se adauga
       :type show: Serial
       :return: -; lista de seriale se modifica prin adaugarea serialului dat
        :rtype:
        :raises: DuplicateIDException daca serialul exista deja
        """
        all_shows = self.__load_from_file()
        if show in all_shows:
            raise DuplicateIDException()

        all_shows.append(show)
        self.__save_to_file(all_shows)

    def get_all(self):
        """
        Returneaza o lista cu toate show-urile existente
        :rtype: list of objects de tip Serial
        """
        return self.__load_from_file()

    def size(self):
        """
        Returneaza numarul de seriale din multime
        :return: numar seriale existente
        :rtype:int
        """
        return len(self.__load_from_file())

    def __find_index(self, all_shows, id):
        """
        Gaseste pozitia in lista a serialului cu id dat
        :param all_shows: lista cu toate serialele
        :type all_shows: list of Serial objects
        :param id: id-ul cautat
        :type id: str
        :return: pozitia in lista a serialului dat, -1 daca serialul nu se regaseste in lista
        :rtype: int, >=0, <repo.size()
        """
        index = -1
        for i in range(len(all_shows)):
            if all_shows[i].getId() == id:
                index = i

        return index

    def delete(self, id):
        """
        Sterge serial dupa id
        :param id: id-ul dat
        :type id: str
        :return: serialul sters
        :rtype: Serial
        :raises: ShowNotFoundException daca id-ul nu exista
        """
        all_shows = self.__load_from_file()
        index = self.__find_index(all_shows, id)
        if index == -1:
            raise ShowNotFoundException()

        deleted_show = all_shows.pop(index)

        self.__save_to_file(all_shows)
        return deleted_show

    def update(self, id, modified_show):
        """
        Modifica datele serialului cu id dat
        :param id: id dat
        :type id: str
        :param modified_show: show-ul cu datele noi
        :type modified_show: Serial
        :return: show-ul modificat
        :rtype: Serial
        :raises: ShowNotFoundException daca nu exista serial cu id dat
        """

        all_shows = self.__load_from_file()
        index = self.__find_index(all_shows, id)
        if index == -1:
            raise ShowNotFoundException()

        all_shows[index] = modified_show

        self.__save_to_file(all_shows)
        return modified_show

    def delete_all(self):
        self.__save_to_file([])


def test_store_file():
    test_repo = ShowFileRepo('test_shows_repo.txt')
    test_repo.delete_all()
    test_repo.store(Serial('123', 'Ozark', 2015, 80))
    assert (test_repo.size() == 1)

    try:
        test_repo.store(Serial('123', 'Ozark', 2015, 80))
        assert False
    except DuplicateIDException:
        assert True


def test_update_file():
    pass


def test_delete_file():
    pass


def test_find_file():
    pass
