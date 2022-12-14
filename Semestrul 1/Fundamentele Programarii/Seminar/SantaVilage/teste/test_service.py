import unittest

from repository.repo_atelier import RepoAtelier
from service.service_atelier import ServiceAtelier


class TestService(unittest.TestCase):

    def setUp(self) -> None:
        self.__repo = RepoAtelier("test_ateliere.txt")
        self.__service = ServiceAtelier(self.__repo)

    def test_cautare_atelier(self):
        lista1 = self.__service.cautare_atelier("cadouri", 200)
        self.assertEqual(len(lista1), 2)
