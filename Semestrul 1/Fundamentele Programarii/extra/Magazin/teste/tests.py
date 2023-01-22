import unittest

from domain.produs import Produs
from repository.repository import RepoMagazin
from service.service import ServiceMagazin


class TestRepository(unittest.TestCase):

    def setUp(self) -> None:
        self.repo = RepoMagazin("./test_produse")

    def test_load_from_file(self):
        self.assertTrue(len(self.repo.load_from_file()), 5)
        lista = self.repo.load_from_file()
        self.assertTrue(lista[1].get_id(), 2)
        self.assertTrue(lista[2].get_id(), 3)

    def test_save_to_file(self):
        lista_initiala = self.repo.load_from_file()
        lista = self.repo.load_from_file()
        lista.append(Produs(1234, "exemplu", 90.99))
        self.repo.save_to_file(lista)
        self.assertTrue(len(self.repo.load_from_file()), 6)
        self.repo.save_to_file(lista_initiala)

class TestService(unittest.TestCase):

    def setUp(self) -> None:
        self.repo = RepoMagazin("./test_produse")
        self.service = ServiceMagazin(self.repo)

    def test_adaugare_produs(self):
        lista_initiala = self.repo.load_from_file()
        self.service.adaugare_produs(1234, "exemplu", 12121)
        lista = self.service.get_all()
        self.assertTrue(lista[len(lista)-1].get_id(), 1234)
        self.assertTrue(lista[len(lista) - 1].get_denumire(), "exemplu")
        self.repo.save_to_file(lista_initiala)
