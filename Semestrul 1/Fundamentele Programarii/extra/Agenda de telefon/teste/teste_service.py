import unittest

from domain.contact import Validator
from repository.repository import ContactRepository
from service.service import AgendaService


class TestService(unittest.TestCase):

    def setUp(self) -> None:
        self.repo = ContactRepository("./test_data")
        self.validator = Validator()
        self.service = AgendaService(self.repo, self.validator)

    def test_adauga_contact(self):
        agenda_initiala = self.repo.load_from_file()
        self.service.adauga_contact(123, "John", 112, "Altele")
        agenda = self.repo.load_from_file()
        self.assertEqual(len(agenda), 8)
        self.assertEqual(agenda[-1].get_nume(), "John")
        self.assertEqual(agenda[-1].get_nrTelefon(), 112)
        self.assertRaises(ValueError, self.service.adauga_contact, 123, "", 3, "nustiu")
        self.assertRaises(ValueError, self.service.adauga_contact, 123, "John", 3, "Altele")
        self.repo.save_to_file(agenda_initiala)

    def test_cautare_numar_telefon(self):
        agenda_initiala = self.repo.load_from_file()
        self.service.adauga_contact(123, "John", 112, "Altele")
        self.assertEqual(self.service.cautare_numar_telefon("John").get_nrTelefon(), 112)
        self.assertRaises(ValueError, self.service.cautare_numar_telefon, "Mircea")
        self.repo.save_to_file(agenda_initiala)

    def test_sortare_grup(self):
        date_grup = self.service.sortare_grup("Prieteni")
        self.assertEqual(date_grup[0].get_nume(), "Andreea")
        self.assertEqual(date_grup[1].get_nume(), "Ion")
        self.assertRaises(ValueError, self.service.sortare_grup, "nuj")