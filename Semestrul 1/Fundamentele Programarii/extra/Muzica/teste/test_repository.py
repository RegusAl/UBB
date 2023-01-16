import unittest

from erori.erori import Validator, ValidError
from repository.repository import Repository
from service.service import Service


class TestRepo(unittest.TestCase):

    def setUp(self) -> None:
        self.__repo = Repository("./test_melodii")

    def test_load_from_file(self):
        self.assertTrue(len(self.__repo.load_from_file()), 8)
        self.assertTrue(self.__repo.load_from_file()[0].get_titlu(), "Baby")
        self.assertTrue(self.__repo.load_from_file()[1].get_titlu(), "November Rain")
        self.assertTrue(self.__repo.load_from_file()[3].get_artist(), "qq")
        self.assertTrue(self.__repo.load_from_file()[6].get_durata(), 61)

class TestService(unittest.TestCase):

    def setUp(self) -> None:
        self.__repo = Repository("./test_melodii")
        self.__validator = Validator()
        self.__service = Service(self.__repo, self.__validator)

    def test_modificare_melodie(self):
        lista_initiala = self.__repo.get_all()
        self.__service.modificare_melodie("bu", "qq", "Rock", 200)
        lista = self.__service.get_all()
        self.assertTrue(lista[3].get_gen(), "Rock")
        self.assertTrue(lista[3].get_durata(), 200)
        self.assertRaises(ValidError, self.__service.modificare_melodie,"", " ", "Roc", -10 )
        self.__repo.save_to_file(lista_initiala)

    def test_melodii_random(self):
        lista_initiala = self.__repo.get_all()
        self.__service.melodii_random(3, ["a","b","c","d"], ["artist1","artist2","artist3","artist4"])
        lista = self.__service.get_all()
        self.assertTrue(len(lista), 11)
        self.__repo.save_to_file(lista_initiala)

    def test_export(self):
        lista_sortata = self.__service.export("test_melodii_sortate.csv")
        self.assertTrue(lista_sortata[0].get_titlu(), "Baby")


