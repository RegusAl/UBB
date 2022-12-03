from domain.entities import Serial
from domain.validators import ShowValidator
from exceptions.exceptions import ShowNotFoundException, ValidationException
from repository.show_repo import ShowInMemoryRepo


class ShowService:
    def __init__(self, repo, validator):
        """
        Initializeaza service
        :param repo: obiect de tip repo care ne ajuta sa gestionam multimea de seriale
        :type repo: ShowInMemoryRepo
        :param validator: validator pentru verificarea serialelor
        :type validator: ShowValidator
        """
        self.__repo = repo
        self.__validator = validator

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
        :raises: ValidationException daca serialul are date invalide
                 DuplicateIDException daca id-ul exista deja in lista
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
        return self.__repo.get_all()

    def delete_show(self, id):
        """
        Sterge serialul cu id dat din lista
        :param id: id-ul dat
        :type id: str
        :return: serialul sters
        :rtype: Serial
        :raises: ShowNotFoundException daca nu exista serial cu id-ul dat
        """
        return self.__repo.delete(id)

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
        :raises: ValidationException daca noile date nu sunt valide
                 ShowNotFoundException daca nu exista serial cu id dat
        """
        s = Serial(id, titlu, an_aparitie, eps)

        self.__validator.validate(s)
        return self.__repo.update(id, s)


