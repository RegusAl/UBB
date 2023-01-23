import unittest

from repository.repository import Repository
from service.service import Service


class TestRepository(unittest.TestCase):

    def setUp(self) -> None:
        self.repository = Repository("./test_data")

    def test_load_from_file(self):
        echipa = self.repository.load_from_file()
        self.assertEqual(len(echipa), 12)
        self.assertEqual(echipa[0].get_nume(), "Graham")
        self.assertEqual(echipa[0].get_prenume(), "Paul")
        self.assertEqual(echipa[1].get_inaltime(), 186)
        self.assertEqual(echipa[1].get_post(), "Extrema")

    def test_save_to_file(self):
        echipa_initiala = self.repository.load_from_file()
        echipa = echipa_initiala[:3]
        self.assertEqual(len(echipa), 3)
        self.assertEqual(echipa[-1].get_nume(), "Popescu")
        self.repository.save_to_file(echipa_initiala)

class TestService(unittest.TestCase):

    def setUp(self) -> None:
        self.repository = Repository("./test_data")
        self.service = Service(self.repository)

    def test_adaugare_jucator(self):
        echipa_initiala = self.repository.load_from_file()
        self.service.adaugare_jucator("ex", "ex", 180, "Pivot")
        echipa = self.repository.load_from_file()
        self.assertEqual(echipa[-1].get_nume(), "ex")
        self.assertEqual(echipa[-1].get_prenume(), "ex")
        self.assertEqual(echipa[-1].get_inaltime(), 180)
        self.assertEqual(echipa[-1].get_post(), "Pivot")
        self.assertRaises(ValueError, self.service.adaugare_jucator, '', '', -90, "nuj")
        self.repository.save_to_file(echipa_initiala)

    def test_modifica_inaltime(self):
        echipa_initiala = self.repository.load_from_file()
        self.service.modifica_inaltime("Graham", "Paul", 210)
        echipa = self.repository.load_from_file()
        self.assertEqual(echipa[0].get_inaltime(), 210)
        self.repository.save_to_file(echipa_initiala)

    def test_echipa_valida(self):
        echipa_valida = self.service.echipa_valida()
        self.assertEqual(len(echipa_valida), 5)
        self.assertEqual(echipa_valida[0].get_nume(), "Graham")
        self.assertEqual(echipa_valida[1].get_nume(), "Alex")

    def test_import_jucatori(self):
        echipa_initiala = self.repository.load_from_file()
        numar = self.service.import_jucatori("./test_jucatori_noi")
        echipa = self.repository.load_from_file()
        self.assertEqual(len(echipa), 13)
        self.assertEqual(numar, 1)
        self.repository.save_to_file(echipa_initiala)
