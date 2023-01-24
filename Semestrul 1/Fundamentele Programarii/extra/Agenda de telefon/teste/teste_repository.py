import unittest

from repository.repository import ContactRepository

class TestRepository(unittest.TestCase):

    def setUp(self) -> None:
        self.repo = ContactRepository("./test_data")

    def test_load_from_file(self):
        agenda = self.repo.load_from_file()
        self.assertEqual(len(agenda), 7)
        self.assertEqual(agenda[0].get_nume(), "Mihai")
        self.assertEqual(agenda[1].get_grup(), "Job")
        self.assertEqual(agenda[1].get_id(), 2)
        self.assertEqual(agenda[1].get_nrTelefon(), 7589534221)

    def test_save_to_file(self):
        agenda_initiala = self.repo.load_from_file()
        self.repo.save_to_file(agenda_initiala[:3])
        agenda = self.repo.load_from_file()
        self.assertEqual(len(agenda), 3)
        self.assertEqual(agenda[2].get_id(), 3)
        self.repo.save_to_file(agenda_initiala)

    def test_get_grup(self):
        self.assertEqual(len(self.repo.get_grup("Familie")), 2)
        self.assertEqual(self.repo.get_grup("Familie")[0].get_nume(), "Alex")