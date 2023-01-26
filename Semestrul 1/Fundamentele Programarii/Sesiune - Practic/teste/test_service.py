import unittest

from repository.repository import Repository
from service.service import Service


class TestService(unittest.TestCase):

    def setUp(self) -> None:
        self.repository = Repository("./test_data")
        self.service = Service(self.repository)

    def test_get_all(self):
        tractoare = self.service.get_all()
        self.assertEqual(len(tractoare), 7)
        self.assertEqual(tractoare[0].get_id(), 1)
        self.assertEqual(tractoare[0].get_pret(), 1500)
        self.assertEqual(tractoare[1].get_denumire(), "tractor agricol")
        self.assertEqual(tractoare[2].get_data(), "12:09:2021")
        self.assertEqual(tractoare[3].get_model(), "model nou")

    def test_adaugare_tractor(self):
        lista_initiala = self.repository.load_from_file()
        self.service.adaugare_tractor(900, "tractor agricol", 3000, "nou", "13:06:2024")
        tractoare = self.service.get_all()
        self.assertEqual(len(tractoare), 8)
        self.assertEqual(tractoare[-1].get_id(), 900)
        self.assertEqual(tractoare[-1].get_denumire(), "tractor agricol")
        self.assertEqual(tractoare[-1].get_pret(), 3000)
        self.assertEqual(tractoare[-1].get_model(), "nou")
        self.assertEqual(tractoare[-1].get_data(), "13:06:2024")
        self.repository.save_to_file(lista_initiala)

    def test_stergere_tractoare(self):
        lista_initiala = self.repository.load_from_file()
        numar = self.service.stergere_tractoare(4)
        tractoare = self.service.get_all()
        self.assertEqual(len(tractoare), 2)
        self.assertEqual(numar, 5)
        self.repository.save_to_file(lista_initiala)

    def test_filtrare(self):
        lista_initiala = self.repository.load_from_file()
        tractoare = self.service.filtrare("", -1)
        self.assertEqual(len(tractoare), 7)
        tractoare = self.service.filtrare("", 500)
        self.assertEqual(len(tractoare), 4)
        self.assertEqual(tractoare[-1].get_denumire(), "*nuj")
        self.assertEqual(tractoare[-2].get_denumire(), "tractor mare")
        self.service.adaugare_tractor(1000, "tractor agricol", 3000, "nou", "13:01:2023")
        tractoare = self.service.filtrare("", -1)
        self.assertEqual(tractoare[-1].get_denumire(), "*tractor agricol")
        self.service.adaugare_tractor(1000, "tractor agricol", 3000, "nou", "30:01:2023")
        tractoare = self.service.filtrare("", -1)
        self.assertEqual(tractoare[-1].get_denumire(), "tractor agricol")
        self.repository.save_to_file(lista_initiala)


    def test_undo(self):
        lista_initiala = self.repository.load_from_file()
        self.service.adaugare_tractor(900, "tractor agricol", 3000, "nou", "13:06:2024")
        self.assertEqual(len(self.service.get_all()), 8)
        self.service.undo()
        self.assertEqual(len(self.service.get_all()), 7)
        self.service.stergere_tractoare(4)
        self.assertEqual(len(self.service.get_all()), 2)
        self.service.undo()
        self.assertEqual(len(self.service.get_all()), 7)
        self.assertEqual(self.service.undo(), None)
        self.repository.save_to_file(lista_initiala)

