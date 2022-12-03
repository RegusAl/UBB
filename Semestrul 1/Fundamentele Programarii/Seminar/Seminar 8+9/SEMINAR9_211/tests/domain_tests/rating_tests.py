import unittest

from domain.validators import RatingValidator

from domain.entities import Serial, Client, Rating
from exceptions.exceptions import ValidationException


class TestCaseRatingDomain(unittest.TestCase):
    def setUp(self) -> None:
        self.__validator = RatingValidator()

    def test_create_rating(self):
        show = Serial('SF123', 'See', 2019, 12)
        client = Client('1', 'Maria', 26)

        rating = Rating('SF123', '1', 4.1)

        self.assertEqual(rating.getSerialId(), 'SF123')
        self.assertEqual(rating.getClientId(), '1')
        self.assertEqual(rating.getNoStars(), 4.1)

    def test_equal_rating(self):
        show = Serial('SF123', 'See', 2019, 12)
        client = Client('1', 'Maria', 26)

        rating1 = Rating('SF123', '1', 4.1)
        rating2 = Rating('SF123', '1', 4.5)

        self.assertEqual(rating1, rating2)

        show2 = Serial('D564', 'Ozark', 2016, 48)
        rating3 = Rating('D564', '1', 3)
        self.assertNotEqual(rating3, rating2)

    def test_rating_validator(self):
        show = Serial('SF123', 'See', 2019, 12)
        client = Client('1', 'Ianis', 26)

        rating = Rating('SF123', 1, 4.1)

        self.__validator = RatingValidator()
        self.__validator.validate(rating)

        rating1 = Rating(show, client, 100)
        self.assertRaises(ValidationException, self.__validator.validate, rating1)
