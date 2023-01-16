import unittest

from domain.entities import Workshop
from exceptions.exceptions import NoWorkshopWithNameException
from repository.workshop_repo import WorkShopRepo


class TestRepoWorkshop(unittest.TestCase):
    def setUp(self) -> None:
        self.__test_repo = WorkShopRepo('test_workshops.txt')

    def test_get_all(self):
        workshops = self.__test_repo.get_all()
        self.assertEqual(len(workshops), 5)

    def test_find(self):
        workshop1 = self.__test_repo.find_by_name("Gingerbread Workshop")
        workshop2 = Workshop("Gingerbread Workshop",
                             "Santa Claus Village, Glittering Street, North Pole",
                             "gingerbread", 19)
        self.assertEqual(workshop1, workshop2)

        self.assertRaises(NoWorkshopWithNameException, self.__test_repo.find_by_name, "Gingerbread and Chocolate Workshop")
