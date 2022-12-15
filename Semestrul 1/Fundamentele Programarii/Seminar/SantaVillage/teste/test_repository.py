import unittest

from repository.repo_atelier import RepoAtelier
from service.service_atelier import ServiceAtelier


class TestRepository(unittest.TestCase):

    def setUp(self) -> None:
        self.__repo = RepoAtelier("test_ateliere.txt")
        self.__service = ServiceAtelier(self.__repo)

    def test_get_all(self):
        lista = self.__repo.get_all()
        self.assertEqual(len(lista), 5)
