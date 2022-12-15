import unittest

from repository.repo_atelier import RepoAtelier
from service.service_atelier import ServiceAtelier
from validare.exceptii import ExceptionProdusNegasit, ExceptionPutiniSpiridusi


class TestService(unittest.TestCase):

    def setUp(self) -> None:
        self.__repo = RepoAtelier("test_ateliere.txt")
        self.__service = ServiceAtelier(self.__repo)

    def test_cautare_atelier(self):
        lista1 = self.__service.cautare_atelier("cadouri", 200)
        self.assertEqual(len(lista1), 2)
        self.assertEqual(lista1[0].get_numar_spiridusi(), 900)
        self.assertEqual(lista1[0].get_locatie(), "Olanda")
        # test pentru Exceptii
        self.assertRaises(ExceptionProdusNegasit, self.__service.cautare_atelier, "exemplu", 0)
        self.assertRaises(ExceptionPutiniSpiridusi, self.__service.cautare_atelier, "cadouri", 1000)

