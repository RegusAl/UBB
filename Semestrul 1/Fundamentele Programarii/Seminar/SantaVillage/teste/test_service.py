import unittest

from repository.repo_atelier import RepoAtelier
from service.service_atelier import ServiceAtelier
from validare.exceptii import ExceptionProdusNegasit, ExceptionPutiniSpiridusi, ExceptionNumeInvalid


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

    def test_organizare_atelier(self):
        atelier1 = self.__service.organizare_atelier("Santa's bodega", 5)
        self.assertEqual(atelier1[0], "Santa's bodega")
        self.assertEqual(atelier1[1], 45)
        self.assertEqual(atelier1[2], "Cluuuj")
        self.assertEqual(atelier1[3], 10 * atelier1[1] * 5)
        self.assertEqual(atelier1[4], 15 * atelier1[1] * 5)
        # test pentru Exceptii
        self.assertRaises(ExceptionNumeInvalid, self.__service.organizare_atelier, "nuj", 100)