import unittest

from repository.repository import RepositoryEvenimente


class TestRepository(unittest.TestCase):

    def setUp(self) -> None:
        self.repo = RepositoryEvenimente("./test_evenimente")

    def test_load_from_file(self):
        evenimente = self.repo.load_from_file()
        self.assertEqual(len(evenimente), 7)
        self.assertEqual(evenimente[0].get_ora(), "14:00")
        self.assertEqual(evenimente[1].get_data(), "25.01.2023")
        self.assertEqual(evenimente[1].get_descriere(), "Laborator ASC")

    def test_save_to_file(self):
        evenimente_initiale = self.repo.load_from_file()
        evenimente = self.repo.load_from_file()
        self.repo.save_to_file(evenimente[3:5])
        evenimente = self.repo.load_from_file()
        self.assertEqual(len(evenimente), 2)
        self.assertEqual(evenimente[0].get_ora(), "14:15")
        self.assertEqual(evenimente[1].get_descriere(), "Laborator FP")
        self.repo.save_to_file(evenimente_initiale)

    def test_get_all_today(self):
        evenimente = self.repo.get_all_today()
        self.assertTrue(len(evenimente), 1)
        self.assertGreaterEqual(len(evenimente), 0)

    def test_export(self):
        self.repo.export("test.txt", self.repo.load_from_file())
        pass