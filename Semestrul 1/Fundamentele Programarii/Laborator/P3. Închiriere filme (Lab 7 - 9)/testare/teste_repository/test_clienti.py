import unittest

from domeniu.clienti import Client
from erori.repo_error import RepoError
from infrastructura.repo_clienti import RepoClienti

class TestCaseRepoClienti(unittest.TestCase):

    def setUp(self) -> None:
        self.__repo = RepoClienti()

    def test_adauga_client(self):
        client = Client(1, "George", 5061234567890)
        self.__repo.adauga_client(client)
        self.assertTrue (self.__repo.__sizeof__(), 1)
        client = Client(1, "Exemplu2", "Aventura")
        self.assertRaises(RepoError, self.__repo.adauga_client, client)

    def test_stergere_client(self):
        self.__repo.adauga_client(Client(1, "Alex", 1231231232345))
        self.__repo.adauga_client(Client(2, "Mihai", 1234567890123))
        self.__repo.adauga_client(Client(3, "George", 1212121223456))
        self.assertRaises(RepoError, self.__repo.stergere_client, 4)