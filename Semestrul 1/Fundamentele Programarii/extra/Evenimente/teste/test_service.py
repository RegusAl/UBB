import unittest

from domain.validare import Validare
from repository.repository import RepositoryEvenimente
from service.service import ServiceEvenimente


class TestService(unittest.TestCase):

    def setUp(self) -> None:
        self.repo = RepositoryEvenimente("./test_evenimente")
        self.validare = Validare()
        self.service = ServiceEvenimente(self.repo, self.validare)

    def test_evenimente_zi_curenta(self):
        self.assertTrue(self.service.evenimente_zi_curenta(), 1)
        self.assertGreaterEqual(len(self.service.evenimente_zi_curenta()), 0)

    def test_adaugare_eveniment(self):
        evenimente_initiale = self.repo.load_from_file()
        self.service.adaugare_eveniment("12.03.2020", "08:00", "exemplu")
        evenimente = self.repo.load_from_file()
        self.assertEqual(len(evenimente), 8)
        self.assertEqual(evenimente[-1].get_ora(), "08:00")
        self.assertEqual(evenimente[-1].get_data(), "12.03.2020")
        self.assertEqual(evenimente[-1].get_descriere(), "exemplu")
        self.assertRaises(ValueError, self.service.adaugare_eveniment, "100.02.2020", "08:00", "ex1")
        self.assertRaises(ValueError, self.service.adaugare_eveniment, "10.02.2020", "25:00", "ex2")
        self.assertRaises(ValueError, self.service.adaugare_eveniment, "10.20.2020", "08:00", "ex3")
        self.assertRaises(ValueError, self.service.adaugare_eveniment, "10.02.2020", "08:67", "ex4")
        self.assertRaises(ValueError, self.service.adaugare_eveniment, "10.02.-2", "08:00", "ex5")
        self.assertRaises(ValueError, self.service.adaugare_eveniment, "10.02.-2", "08:-90", "ex5")
        self.repo.save_to_file(evenimente_initiale)

    def test_stabilire_data(self):
        evenimente = self.service.stabilire_data("26.01.2023")
        self.assertEqual(len(evenimente), 2)
        self.assertEqual(evenimente[0].get_ora(), "14:00")
        self.assertEqual(evenimente[0].get_descriere(), "Examen FP")
        self.assertEqual(evenimente[1].get_ora(), "09:00")

    def test_export(self):
        evenimente = self.service.export("test.txt", "xam")
        self.assertEqual(len(evenimente), 4)
        self.assertEqual(evenimente[0].get_data(), "24.01.2023")
        self.assertEqual(evenimente[1].get_data(), "24.01.2023")
        self.assertEqual(evenimente[2].get_data(), "25.01.2023")
        self.assertEqual(evenimente[3].get_data(), "26.01.2023")
