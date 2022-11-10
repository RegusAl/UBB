from domain.entities import Serial
from domain.validators import ShowValidator
from repository.show_repo import InMemoryRepository


class ShowService:
    """
        GRASP Controller (Curs 6)
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

    def add_show(self, titlu, an_aparitie, eps):
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
        :raises: ValueError daca serialul are date invalide
        """
        s = Serial(titlu, an_aparitie, eps)

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

    def delete_shows(self,an_inceput, an_sfarsit):
        pass


def test_add_show():
    repo = InMemoryRepository()
    validator = ShowValidator()
    test_srv = ShowService(repo, validator)

    added_show = test_srv.add_show('See', 2019, 12)
    assert (added_show.getTitle()=='See')
    assert (added_show.getEpisoade()==12)

    assert (len(test_srv.get_all_shows()) == 1)

    try:
        added_show = test_srv.add_show('See', 1200, 12)
        assert False
    except ValueError:
        assert True