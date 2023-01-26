import unittest

from domain.tractor import Tractor
from repository.repository import Repository


class TestRepository(unittest.TestCase):

    def setUp(self) -> None:
        self.repository = Repository("./test_data")

    def test_load_from_file(self):
        tractoare = self.repository.load_from_file()
        self.assertEqual(len(tractoare), 7)
        self.assertEqual(tractoare[0].get_id(), 1)
        self.assertEqual(tractoare[0].get_pret(), 1500)
        self.assertEqual(tractoare[1].get_denumire(), "tractor agricol")
        self.assertEqual(tractoare[2].get_data(), "12:09:2021")
        self.assertEqual(tractoare[3].get_model(), "model nou")

    def test_save_to_file(self):
        lista_initiala = self.repository.load_from_file()
        tractoare = lista_initiala[:4]
        self.assertEqual(len(tractoare), 4)
        self.repository.save_to_file(tractoare)
        self.assertEqual(len(self.repository.load_from_file()), 4)
        self.repository.save_to_file(lista_initiala)

    def test_add(self):
        lista_initiala = self.repository.load_from_file()
        self.repository.add(Tractor(9, "tractor", 9000, "model vechi", "09:01:2010"))
        self.assertEqual(len(self.repository.load_from_file()), 8)
        self.assertEqual(self.repository.load_from_file()[-1].get_id(), 9)
        self.assertEqual(self.repository.load_from_file()[-1].get_denumire(), "tractor")
        self.assertEqual(self.repository.load_from_file()[-1].get_pret(), 9000)
        self.assertEqual(self.repository.load_from_file()[-1].get_model(), "model vechi")
        self.assertEqual(self.repository.load_from_file()[-1].get_data(), "09:01:2010")
        self.repository.save_to_file(lista_initiala)

    def test_delete(self):
        lista_initiala = self.repository.load_from_file()
        self.repository.delete(80)
        self.assertEqual(len(self.repository.load_from_file()), 6)
        self.repository.delete(400)
        self.assertEqual(len(self.repository.load_from_file()), 6)
        self.repository.save_to_file(lista_initiala)

    def test_get_all(self):
        tractoare = self.repository.get_all()
        self.assertEqual(len(tractoare), 7)
        self.assertEqual(tractoare[0].get_id(), 1)
        self.assertEqual(tractoare[0].get_pret(), 1500)
        self.assertEqual(tractoare[1].get_denumire(), "tractor agricol")
        self.assertEqual(tractoare[2].get_data(), "12:09:2021")
        self.assertEqual(tractoare[3].get_model(), "model nou")





