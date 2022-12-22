import unittest

from domeniu.pantof import Pantof
from repository.repo_pantofi import RepoPantofi


class TestRepo(unittest.TestCase):

    def setUp(self) -> None:
        self.__repo = RepoPantofi("test-pantof.txt")

    def test_load_from_file(self):
        lista_pantofi = self.__repo._load_from_file()
        self.assertEqual(len(lista_pantofi), 6)
        self.assertEqual(lista_pantofi[0].get_id(), 1)
        self.assertEqual(lista_pantofi[3].get_marime(), 38)
        self.assertEqual(lista_pantofi[5].get_pret(), 1200)

    def test_get_all(self):
        lista_pantofi = self.__repo.get_all()
        self.assertEqual(len(lista_pantofi), 6)
        self.assertEqual(lista_pantofi[0].get_id(), 1)
        self.assertEqual(lista_pantofi[3].get_marime(), 38)
        self.assertEqual(lista_pantofi[5].get_pret(), 1200)

    def test_save_to_file(self):
        l = self.__repo.get_all()
        lista_pantofi = self.__repo.get_all()
        lista_pantofi.append(Pantof(7, "Ex", 40, 10, 234, "False"))
        self.assertEqual(len(lista_pantofi), 7)
        self.__repo._save_to_file(lista_pantofi)
        lista_pantofi = self.__repo.get_all()
        self.assertEqual(len(lista_pantofi), 7)
        self.__repo._save_to_file(l)
