from domain.entities import Client
from domain.validators import ClientValidator


class ClientService:
    def __init__(self, repo, validator):
        """
        Initializeaza service
        :param repo: obiect de tip repo care ne ajuta sa gestionam multimea de clienti
        :type repo: ClientRepo
        :param validator: validator pentru verificarea clientilor
        :type validator: ClientValidator
        """
        self.__repo = repo
        self.__validator = validator

    def add_client(self, id, nume, varsta):
        """
        Adauga client
        :param id: id-ul clientului
        :type id: str
        :param nume: numele clientului
        :type nume: str
        :param varsta: varsta clientului
        :type varsta: int
        :return: Clientul adaugat
        :rtype: Client
        :raises: ValidationException daca datele pentru client nu sunt valide
                 DuplicateIDException daca exista deja client cu id dat
        """
        c = Client(id, nume, varsta)
        self.__validator.validate(c)
        self.__repo.store(c)
        return c

    def get_all_clients(self):
        """
        Returneaza o lista cu toti clientii disponibili
        :return: lista de clienti disponibili
        :rtype: list of objects de tip Client
        """
        return self.__repo.get_all()

    def delete_client(self, id):
        """
        Sterge clientul cu id dat din lista
        :param id: id-ul dat
        :type id: str
        :return: clientul sters
        :rtype: Client
        :raises: ClientNotFoundException daca nu exista client cu id-ul dat
        """
        return self.__repo.delete(id)

    def update_client(self, id, nume, varsta):
        """
        Modifica datele clientului cu id dat
        :param id: id-ul clientului de modificat
        :type id: str
        :param nume: noul nume al clientului
        :type nume: str
        :param varsta: noua varsta a clientului
        :type varsta: int
        :return: clientul modificat
        :rtype:Client
        :raises: ValidationException daca datele nu sunt valide
                 ClientNotFoundException daca nu exista client cu id-ul dat
        """
        c = Client(id, nume, varsta)

        self.__validator.validate(c)
        return self.__repo.update(id, c)
