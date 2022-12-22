import unittest

from repository.repo_pantofi import RepoPantofi
from service.service_pantofi import ServicePantofi
from validator.validator import Validator, RepoError


class TestService(unittest.TestCase):

    def setUp(self) -> None:
        self.__repo = RepoPantofi("test-pantof.txt")
        self.__validator = Validator()
        self.__service = ServicePantofi(self.__repo, self.__validator)

    def test_get_all(self):
        lista_pantofi = self.__service.get_all()
        self.assertEqual(len(lista_pantofi), 6)
        self.assertEqual(lista_pantofi[0].get_id(), 1)
        self.assertEqual(lista_pantofi[3].get_marime(), 38)
        self.assertEqual(lista_pantofi[5].get_pret(), 1200)

    def test_afisare_dupa_denumire(self):
        l = self.__service.get_all()
        lista = self.__service.afisare_dupa_denumire("Adidas")
        self.assertEqual(len(lista), 1)
        lista = self.__service.afisare_dupa_denumire("Valentino Garavani")
        self.assertEqual(len(lista), 3)
        self.assertEqual(lista[0].get_marime(), 36)
        self.assertRaises(RepoError, self.__service.afisare_dupa_denumire, "ex")
        self.__repo._save_to_file(l)

    def test_comandare(self):
        l = self.__service.get_all()
        lista = self.__service.comandare(1)
        self.assertEqual(lista[0].get_numar_perechi(), 3)
        lista = self.__service.comandare(1)
        lista = self.__service.comandare(1)
        lista = self.__service.comandare(1)
        self.assertEqual(lista[0].get_numar_perechi(), 0)
        self.assertRaises(RepoError, self.__service.comandare, 1)
        self.__repo._save_to_file(l)
