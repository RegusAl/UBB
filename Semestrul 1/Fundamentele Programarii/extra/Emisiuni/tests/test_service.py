import unittest

from erori.erori import RepoError, BlocatError
from repository.repo_emisiune import RepoEmisiune
from service.service_emisiune import ServiceEmisiune

class TestService(unittest.TestCase):

    def setUp(self) -> None:
        self.repo = RepoEmisiune("emisiuni_test")
        self.service = ServiceEmisiune(self.repo)

    def test_get_all(self):
        lista_emisiuni = self.service.get_all()
        self.assertEqual(len(lista_emisiuni), 5)
        self.assertEqual(lista_emisiuni[1].get_nume(), "Reportaj")
        self.assertEqual(lista_emisiuni[2].get_tip(), "Film")
        self.assertEqual(lista_emisiuni[3].get_durata(), 2)
        self.assertEqual(lista_emisiuni[4].get_descriere(), "Recorder")

    def test_stergere_emisiune(self):
        lista_inainte = self.service.get_all()
        self.service.stergere_emisiune("Jurnal", "Stiri")
        lista = self.service.get_all()
        self.assertEqual(len(lista), 4)
        # RepoError
        self.assertRaises(RepoError, self.service.stergere_emisiune, "ex", "ex")
        # BlocatError
        self.service.blocare_tip("Film")
        self.assertRaises(BlocatError, self.service.stergere_emisiune, "Divertisment", "Film")
        self.repo.save_to_file(lista_inainte)

    def test_modificare_emisiune(self):
        lista_inainte = self.service.get_all()
        self.service.modificare_emisiune("Jurnal", "Stiri", 3, "lool")
        lista = self.service.get_all()
        self.assertEqual(lista[0].get_durata(), 3)
        self.assertEqual(lista[0].get_descriere(), "lool")
        # RepoError
        self.assertRaises(RepoError, self.service.modificare_emisiune, "ex", "ex", 3, "looool")
        # BlocatError
        self.service.blocare_tip("Film")
        self.assertRaises(BlocatError, self.service.modificare_emisiune, "Divertisment", "Film", 45, "nuj")
        self.repo.save_to_file(lista_inainte)
