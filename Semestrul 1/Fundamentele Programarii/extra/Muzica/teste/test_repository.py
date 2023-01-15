import unittest

from repository.repository import Repository


class TestRepo(unittest.TestCase):

    def setUp(self) -> None:
        self.__repo = Repository("./test_melodii")

    def test_load_from_file(self):
        self.assertTrue(len(self.__repo.load_from_file()), 8)
        self.assertTrue(self.__repo.load_from_file()[0].get_titlu(), "Baby")
        self.assertTrue(self.__repo.load_from_file()[1].get_titlu(), "November Rain")
        self.assertTrue(self.__repo.load_from_file()[3].get_artist(), "qq")
        self.assertTrue(self.__repo.load_from_file()[6].get_durata(), 61)
