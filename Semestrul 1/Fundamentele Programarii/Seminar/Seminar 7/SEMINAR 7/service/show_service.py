from domain.entities import Serial
from domain.validators import ShowValidator
from repository.show_repo import InMemoryRepository


class ShowService:
    """
        GRASP Controller
        Responsabil de efectuarea operatiilor cerute de utilizator
        Coordoneaza operatiile necesare pentru a realiza actiunea declansata de utilizator
        (i.e. declansare actiune: utilizator -> ui-> obiect tip service in ui -> service -> service coordoneaza operatiile
        folosind alte obiecte (e.g. repo, validator) pentru a realiza efectiv operatia)
        """

    def __init__(self, repo, validator):
        """
        Initializeaza service
        :param repo: obiect de tip repo care ne ajuta sa gestionam multimea de seriale
        :type repo: InMemoryRepository
        :param validator: validator pentru verificarea serialelor
        :type validator: ShowValidator
        """
        self.__repo = repo
        self.__validator = validator



    # def __add_default_shows(self):
    #     self.add_show('1', 'SEAL Team', 2017, 105)
    #     self.add_show('2', 'Supernatural', 2005, 327)
    #     self.add_show('3', 'Friends', 1996, 200)
    #     self.add_show('4', 'Manifest', 2018, 94)
    #     self.add_show('5', 'Fire Country', 2022, 6)

    def add_show(self, id, titlu, an_aparitie, eps):
        """
        Adauga serial
        :param titlu: titlul serialului
        :type titlu:str
        :param an_aparitie: anul de aparitie al serialului
        :type an_aparitie:int
        :param eps:numarul de episoade al serialului
        :type eps:int
        :return: obiectul de tip Serial creat
        :rtype:-; serialul s-a adaugat in lista
        :raises: ValueError daca serialul are date invalide, daca id-ul exista deja in lista
        """
        s = Serial(id, titlu, an_aparitie, eps)

        self.__validator.validate(s)

        self.__repo.store(s)
        return s

    def get_all_shows(self):
        """
        Returneaza o lista cu toate serialele disponibile
        :return: lista de seriale disponibile
        :rtype: list of objects de tip Serial
        """
        return self.__repo.get_all_shows()

    def delete_show(self, id):
        """
        Sterge serialul cu id dat din lista
        :param id: id-ul dat
        :type id: str
        :return: serialul sters
        :rtype: Serial
        :raises: ValueError daca nu exista serial cu id-ul dat
        """
        return self.__repo.delete_by_id(id)

    def update_show(self, id, titlu, an_aparitie, eps):
        """
        Modifica datele serialului cu id dat
        :param id: id-ul serialului de modificat
        :type id: str
        :param titlu: noul titlu al serialului
        :type titlu: str
        :param an_aparitie: noul an de aparitie al serialului
        :type an_aparitie: int
        :param eps: noul numar de episoade pentru serial
        :type eps: int
        :return: serialul modificat
        :rtype:Serial
        :raises: ValueError daca noile date nu sunt valide, sau nu exista serial cu id dat
        """
        s = Serial(id, titlu, an_aparitie, eps)

        self.__validator.validate(s)
        return self.__repo.update(id, s)

    def delete_by_years(self, year_start, year_end):
        """
        Sterge toate serialele din perioada year_start - year_end
        :param year_start: anul de inceput al perioadei
        :type year_start: int
        :param year_end: anul de sfarsit al perioadei
        :type year_end: int (year_start < year_end)
        :return: numarul de seriale sterse
        :rtype: int
        """
        how_many_deleted = self.__repo.delete_by_criteria(
            lambda x: year_start <= x.getAnAparitie() <= year_end)
        return how_many_deleted

    def filter_by_no_episodes(self, number_of_episodes):
        """
        Returneaza lista de seriale care au mai multe episoade decat numarul dat
        :param number_of_episodes: numarul de episoade dat
        :type number_of_episodes:int
        :return: lista de seriale care indeplinesc criteriul
        :rtype: list of Serial objects
        """
        all_shows = self.get_all_shows()
        filtered_list = [show for show in all_shows if show.getEpisoade() > number_of_episodes]
        return filtered_list


def test_add_show():
    repo = InMemoryRepository()
    validator = ShowValidator()
    test_srv = ShowService(repo, validator)

    added_show = test_srv.add_show('1', 'See', 2019, 12)
    assert (added_show.getTitle() == 'See')
    assert (added_show.getEpisoade() == 12)

    assert (len(test_srv.get_all_shows()) == 1)

    try:
        added_show = test_srv.add_show('2', 'See', 1200, 12)
        assert False
    except ValueError:
        assert True


def test_delete_show():
    repo = InMemoryRepository()
    validator = ShowValidator()
    test_srv = ShowService(repo, validator)

    test_srv.add_show('1', 'See', 2019, 12)
    deleted_show = test_srv.delete_show('1')

    assert (len(test_srv.get_all_shows()) == 0)
    assert (deleted_show.getTitle() == 'See')
    assert (deleted_show.getAnAparitie() == 2019)
    assert (deleted_show.getEpisoade() == 12)

    try:
        test_srv.delete_show('2')
        assert False
    except ValueError:
        assert True


def test_get_all_shows():
    repo = InMemoryRepository()
    validator = ShowValidator()
    test_srv = ShowService(repo, validator)

    test_srv.add_show('1', 'See', 2019, 16)
    test_srv.add_show('2', 'Modern Family', 2009, 250)
    assert (type(test_srv.get_all_shows()) == list)
    assert (len(test_srv.get_all_shows()) == 2)


def test_update_show():
    repo = InMemoryRepository()
    validator = ShowValidator()
    test_srv = ShowService(repo, validator)

    test_srv.add_show('1', 'See', 2019, 12)
    updated_show = test_srv.update_show('1', 'See (TV SHOW)', 2019, 16)

    assert (updated_show.getTitle() == 'See (TV SHOW)')
    assert (updated_show.getAnAparitie() == 2019)
    assert (updated_show.getEpisoade() == 16)

    try:
        test_srv.update_show('INVALID ID', 'See', 2019, 16)
        assert False
    except ValueError:
        assert True


def test_delete_by_years():
    repo = InMemoryRepository()
    validator = ShowValidator()
    test_srv = ShowService(repo, validator)

    test_srv.add_show('1', 'See', 2019, 16)
    test_srv.add_show('2', 'Squid Game', 2021, 9)
    test_srv.add_show('3', 'The Magicians', 2015, 65)
    test_srv.add_show('4', 'ER', 1994, 331)
    test_srv.add_show('5', 'Grey\'s Anatomy', 2005, 384)

    how_many_deleted = test_srv.delete_by_years(2010, 2020)
    assert (how_many_deleted == 2)
    assert (len(test_srv.get_all_shows()) == 3)

    how_many_deleted = test_srv.delete_by_years(1985, 1990)
    assert (how_many_deleted == 0)
    assert (len(test_srv.get_all_shows()) == 3)

    how_many_deleted = test_srv.delete_by_years(1992, 2006)
    assert (how_many_deleted == 2)
    assert (len(test_srv.get_all_shows()) == 1)

def test_filter_by_episodes():
    repo = InMemoryRepository()
    validator = ShowValidator()
    test_srv = ShowService(repo, validator)

    test_srv.add_show('1', 'See', 2019, 16)
    test_srv.add_show('2', 'Squid Game', 2021, 9)
    test_srv.add_show('3', 'The Magicians', 2015, 65)
    test_srv.add_show('4', 'ER', 1994, 331)
    test_srv.add_show('5', 'Grey\'s Anatomy', 2005, 384)

    filtered_list = test_srv.filter_by_no_episodes(10)
    assert(len(filtered_list)==4)
    assert (len(test_srv.get_all_shows()) == 5)

    filtered_list = test_srv.filter_by_no_episodes(300)
    assert (len(filtered_list) == 2)
    assert (len(test_srv.get_all_shows()) == 5)

    filtered_list = test_srv.filter_by_no_episodes(150)
    assert (len(filtered_list) == 2)
    assert (len(test_srv.get_all_shows()) == 5)

    filtered_list = test_srv.filter_by_no_episodes(50)
    assert (len(filtered_list) == 3)
    assert (len(test_srv.get_all_shows()) == 5)


