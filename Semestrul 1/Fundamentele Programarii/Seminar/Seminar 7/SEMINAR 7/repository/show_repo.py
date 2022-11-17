import math

from domain.entities import Serial


class InMemoryRepository:
    """
        Clasa creata cu responsabilitatea de a gestiona
        multimea de seriale (i.e. sa ofere un depozit persistent pentru obiecte
        de tip serial)

        CReateUpdateDelete
    """

    def __init__(self):
        # [serial1, serial2, serial3]
        self.__shows = []

    def find(self, id):
        """
        Cauta serialul cu id dat
        :param id: id dat
        :type id: str
        :return: serialul cu id dat, None daca nu exista
        :rtype: Serial
        """
        for show in self.__shows:
            if show.getId() == id:
                return show
        return None

    def __find_index(self, id):
        """
        Gaseste index-ul (pozitia) pe care este serialul cu id dat
        :param id: id dat
        :type id: str
        :return: pozitia in lista a serialului cu id dat, -1 daca serialul nu exista
        :rtype: int (>=0, <repo.size())
        """
        index = -1
        for i in range(self.size()):
            if self.__shows[i].getId() == id:
                index = i
        return index

    def store(self, show):
        """
        Adauga un serial in lista
        :param show: serialul care se adauga
        :type show: Serial
        :return: -; lista de seriale se modifica prin adaugarea serialului dat
        :rtype:
        :raises: ValueError daca serialul exista deja
        """
        # verificare id duplicat
        if self.find(show.getId()) is not None:
            raise ValueError('Exista deja serial cu acest id.')

        self.__shows.append(show)

    def get_all_shows(self):
        """
        Returneaza o lista cu toate show-urile existente
        :rtype: list of objects de tip Serial
        """
        return self.__shows

    def size(self):
        """
        Returneaza numarul de seriale din multime
        :return: numar seriale existente
        :rtype:int
        """
        return len(self.__shows)

    def delete_by_id(self, id):
        """
        Sterge serial dupa id
        :param id: id-ul dat
        :type id: str
        :return: serialul sters
        :rtype: Serial
        :raises: ValueError daca id-ul nu exista
        """

        #varianta remove by value
        show = self.find(id)
        if show is None:
            raise ValueError('Nu exista serial cu acest id.')

        self.__shows.remove(show)
        return show

        #remove by index
        # index = self.__find_index(id)
        # if index == -1:
        #     raise ValueError('Nu exista serial cu acest id.')
        #
        # deleted_show = self.__shows.pop(index)
        # return deleted_show

        # remove (value)
        # pop(index)
        #putem folosi si del list[index] cum am facut la seminar



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

        # self.delete_by_id(id)
        # self.store(modified_show)
        # return modified_show

        show = self.find(id)
        if show is None:
            raise ValueError('Nu exista serial cu acest id.')

        show.setTitle(modified_show.getTitle())
        show.setEpisoade(modified_show.getEpisoade())
        show.setAnAparitie(modified_show.getAnAparitie())
        return show

        # index = self.__find_index(id)
        # if index == -1:
        #     raise ValueError('Nu exista serial cu acest id.')
        #
        # old_show = self.__shows[index]
        # self.__shows[index] = modified_show
        # return modified_show

    def delete_by_criteria(self, filter_function):
        """
        Sterge serialele din multime dupa un criteriu dat
        :param filter_function: functia (criteriul dupa care se sterg serialele)
        :type filter_function: function
        :return: numarul de seriale sterse
        :rtype: int
        """
        initial_no_shows = self.size()
        self.__shows = [show for show in self.__shows if not filter_function(show)]
        return initial_no_shows - self.size()

    def delete_all(self):
        """
        Sterge toate serialele din lista
        """
        self.__shows.clear()
        # self.__shows = []

    def get_shows_by_criteria(self, filter_function):
        """
        Selecteaza elementele din multime care indeplinesc un criteriu
        :param filter_function: functia dupa care se filtreaza
        :type filter_function: function
        :return: lista de seriale care indeplinesc criteriul
        :rtype: list of shows
        """
        return [show for show in self.__shows if filter_function(show)]


class InMemoryRepoDict:
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
        :raises: ValueError daca serialul exista deja
        """
        # verificare id duplicat
        if show.getId() in self.__shows:
            raise ValueError('Exista deja serial cu acest id.')

        self.__shows[show.getId()] = show

    def get_all_shows(self):
        """
        Returneaza o lista cu toate show-urile existente
        :rtype: list of objects de tip Serial
        """
        return self.__shows.values()

    def size(self):
        """
        Returneaza numarul de seriale din multime
        :return: numar seriale existente
        :rtype:int
        """
        return len(self.__shows)

    def delete_by_id(self, id):
        """
        Sterge serial dupa id
        :param id: id-ul dat
        :type id: str
        :return: serialul sters
        :rtype: Serial
        :raises: ValueError daca id-ul nu exista
        """
        if id not in self.__shows:
            raise ValueError('Nu exista serial cu acest id')

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
            raise ValueError('Nu exista serial cu acest id')

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

    test_repo = InMemoryRepository()
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
    test_repo1.delete_by_id('C1001')
    test_repo1.delete_by_id('F2638')

    assert (test_repo1.size() == 8)

    test_repo1.store(Serial('HD2384', 'The Crown', 2016, 41))
    assert (test_repo1.size() == 9)
    test_repo1.update('HD2384', Serial('HD2384', 'The Crown', 2016, 40))
    assert (test_repo1.size() == 9)


def test_get_all_shows():
    test_repo1 = setup_test_repo()
    crt_shows = test_repo1.get_all_shows()
    assert (type(crt_shows) == list)
    assert (len(crt_shows) == 10)

    test_repo1.delete_by_id('C1001')
    test_repo1.delete_by_id('F2638')

    crt_shows = test_repo1.get_all_shows()
    assert (len(crt_shows) == 8)

    test_repo1.store(Serial('HD2384', 'The Crown', 2016, 41))
    assert (test_repo1.size() == 9)

    # not a good test if we don't know if the show is stored on the last position or not
    # e.g. what is returned from get_all_shows for RepoDict?
    assert (test_repo1.get_all_shows()[-1].getTitle() == 'The Crown')
    assert (test_repo1.get_all_shows()[-1].getAnAparitie() == 2016)

    test_repo1.update('HD2384', Serial('HD2384', 'The Crown', 2016, 40))

    # is it always the case that the updated show keeps its position?
    # e.g. implement update as delete(old_show) + insert(new_show)

    assert (test_repo1.get_all_shows()[-1].getEpisoade() == 40)
    assert (test_repo1.size() == 9)


def test_store():
    test_repo = InMemoryRepository()
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
    except ValueError:
        assert True


def test_delete():
    test_repo = InMemoryRepository()
    show1 = Serial('23', 'See', 2019, 12)
    test_repo.store(show1)
    show2 = Serial('234', 'Kim\'s Convenience', 2016, 67)
    test_repo.store(show2)

    deleted_show = test_repo.delete_by_id('234')
    assert (deleted_show.getTitle() == 'Kim\'s Convenience')
    assert (test_repo.size() == 1)

    show_left = test_repo.find('23')
    assert (show_left.getTitle() == 'See')

    try:
        test_repo.delete_by_id('wrongid')
        assert False
    except ValueError:
        assert True


def test_update():
    test_repo = InMemoryRepository()
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
    except ValueError:
        assert True


def test_delete_by_criteria():
    test_repo = setup_test_repo()

    # we assume x is a Serial entity in the lambda fn
    # https://www.w3schools.com/python/python_lambda.asp

    # sterge serialele care contin 'the' in titlu
    filter_by_name1 = lambda x: 'The' in x.getTitle() or 'the' in x.getTitle()
    test_repo.delete_by_criteria(filter_by_name1)
    assert (test_repo.size() == 8)

    # sterge serialele care au titlul format dintr-un singur cuvant
    filter_by_name2 = lambda x: len(x.getTitle().split()) == 1
    test_repo.delete_by_criteria(filter_by_name2)
    # test_repo is modified from previous delete, only 8 shows
    assert (test_repo.size() == 3)

    # sterge serialele pentru care titlul incepe cu litera 'G'
    filter_by_name3 = lambda x: x.getTitle().startswith('G')
    test_repo.delete_by_criteria(filter_by_name3)
    # test_repo is modified from previous delete, only 3 shows
    assert (test_repo.size() == 2)

    # sterge serialele pentru care numele contine mai mult de 8 caractere
    filter_by_name4 = lambda x: len(x.getTitle()) > 8
    test_repo.delete_by_criteria(filter_by_name4)
    # test_repo is modified from previous delete, only 2 shows
    assert (test_repo.size() == 0)

    # delete by year
    test_repo2 = setup_test_repo()

    # sterge serialele din anul 2019
    filter_by_year1 = lambda x: x.getAnAparitie() == 2019
    how_many_deleted = test_repo2.delete_by_criteria(filter_by_year1)
    assert (how_many_deleted == 2)
    assert (test_repo2.size() == 8)

    # sterge seriale din perioada 2010-2021
    test_repo2 = setup_test_repo()

    filter_by_year2 = lambda x: 2010 <= x.getAnAparitie() <= 2021
    how_many_deleted = test_repo2.delete_by_criteria(filter_by_year2)
    assert (how_many_deleted == 6)
    assert (test_repo2.size() == 4)

    # sterge serialele din an multiplu de 10
    test_repo2 = setup_test_repo()

    filter_by_year3 = lambda x: x.getAnAparitie() % 10 == 0
    how_many_deleted = test_repo2.delete_by_criteria(filter_by_year3)
    assert (how_many_deleted == 0)
    assert (test_repo2.size() == 10)

    # delete by number of episodes

    # sterge serialele cu mai mult de 200 episoade
    test_repo3 = setup_test_repo()

    filter_by_eps1 = lambda x: x.getEpisoade() > 200
    how_many_deleted = test_repo3.delete_by_criteria(filter_by_eps1)
    assert (how_many_deleted == 4)
    assert (test_repo3.size() == 6)

    # sterge serialele pentru care numarul de episoade este patrat perfect
    test_repo3 = setup_test_repo()

    filter_by_eps1 = lambda x: math.sqrt(x.getEpisoade()) - int(math.sqrt(x.getEpisoade())) == 0
    how_many_deleted = test_repo3.delete_by_criteria(filter_by_eps1)
    assert (how_many_deleted == 2)
    assert (test_repo3.size() == 8)


# utility function - left here just to be easier to see how it works
# and that we can use also functions defined by us
# the only condition - they return True/False so they are evaluated properly
def has_numbers(inputString):
    """
    Verifica daca un string contine numere
    :param inputString: string-ul dat
    :type inputString: str
    :return: True daca string-ul contine numere, False altfel
    :rtype: bool
    """
    return any(char.isdigit() for char in inputString)


def test_filter_by_criteria():
    test_repo = setup_test_repo()

    # we assume x is a Serial entity in the lambda fn
    # https://www.w3schools.com/python/python_lambda.asp

    # selecteaza serialele care contin numere in titlu
    filter_by_name1 = lambda x: has_numbers(x.getTitle())
    filtered_list = test_repo.get_shows_by_criteria(filter_by_name1)
    assert (len(filtered_list) == 0)
    assert (test_repo.size() == 10)

    # selecteaza serialele al caror nume se termina cu litera 's'
    filter_by_name2 = lambda x: x.getTitle().endswith('s')
    filtered_list = test_repo.get_shows_by_criteria(filter_by_name2)
    assert (len(filtered_list) == 2)
    assert (test_repo.size() == 10)

    # selecteaza serialele pentru care anul aparitiei este impar
    filter_by_year1 = lambda x: x.getAnAparitie() % 2 == 1
    filtered_list = test_repo.get_shows_by_criteria(filter_by_year1)
    assert (len(filtered_list) == 8)
    assert (test_repo.size() == 10)

    # selecteaza serialele pentru care anul aparitiei este impar si numarul de episoade este par
    filter_by_year_eps1 = lambda x: x.getAnAparitie() % 2 == 1 and x.getEpisoade() % 2 == 0
    filtered_list = test_repo.get_shows_by_criteria(filter_by_year_eps1)
    assert (len(filtered_list) == 6)
    assert (test_repo.size() == 10)
