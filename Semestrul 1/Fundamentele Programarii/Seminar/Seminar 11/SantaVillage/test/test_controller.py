import unittest

from exceptions.exceptions import NotEnoughElvesException, NoWorkshopsWithTypeException
from repository.workshop_repo import WorkShopRepo
from service.workshop_controller import WorkshopController


class TestRepoWorkshop(unittest.TestCase):
    def setUp(self) -> None:
        self.__test_repo = WorkShopRepo('test_workshops.txt')
        self.__test_ctrl = WorkshopController(self.__test_repo)

    def test_get_all(self):
        workshops = self.__test_ctrl.get_all()
        self.assertEqual(len(workshops), 5)

    def test_get_all_with_type_and_elves(self):
        prod_type = 'decoration'
        no_elves = 20
        requested_workshops = self.__test_ctrl.get_all_with_type_and_elves(prod_type, no_elves)
        self.assertEqual(len(requested_workshops), 1)

        prod_type = 'decoration'
        no_elves = 200
        self.assertRaises(NotEnoughElvesException, self.__test_ctrl.get_all_with_type_and_elves, prod_type, no_elves)

        prod_type = 'Easter decorations'
        no_elves = 50
        self.assertRaises(NoWorkshopsWithTypeException, self.__test_ctrl.get_all_with_type_and_elves, prod_type,
                          no_elves)

    def test_evaluate_workshop(self):
        name = "Santa’s Office"
        no_days = 25

        evaluation = self.__test_ctrl.evaluate_workshop(name, no_days)
        self.assertEqual(evaluation.get_min_products(), 13000)
        self.assertEqual(evaluation.get_max_products(), 19500)
