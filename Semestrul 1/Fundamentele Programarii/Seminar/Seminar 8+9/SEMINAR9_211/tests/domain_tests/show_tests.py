import unittest

from domain.entities import Serial
from domain.validators import ShowValidator
from exceptions.exceptions import ValidationException


class TestCaseShowDomain(unittest.TestCase):
    def setUp(self) -> None:
        self.__validator = ShowValidator()

    def test_create_serial(self):
        show1 = Serial('SF123', 'See', 2019, 12)
        self.assertEqual(show1.getTitle(), 'See')
        self.assertEqual(show1.getAnAparitie(), 2019)
        self.assertEqual(show1.getEpisoade(), 12)

        show1.setTitle('See (2021)')
        show1.setAnAparitie(2021)
        show1.setEpisoade(1)

        self.assertEqual(show1.getTitle(), 'See (2021)')
        self.assertEqual(show1.getAnAparitie(), 2021)
        self.assertEqual(show1.getEpisoade(), 1)

    def test_equals_serial(self):
        show1 = Serial('23', 'See', 2019, 12)
        show2 = Serial('23', 'See', 2019, 10)

        self.assertEqual(show1, show2)

        show3 = Serial('SF1', 'See', 2018, 12)
        self.assertNotEqual(show1,show3)

    def test_show_validator(self):
        show1 = Serial('1', 'See', 2019, 12)
        self.__validator.validate(show1)
        show2 = Serial('2', '', 2050, 55)
        show3 = Serial('3', 'See', 2019, -55)

        self.assertRaises(ValidationException, self.__validator.validate, show2)
        self.assertRaises(ValidationException, self.__validator.validate, show3)
