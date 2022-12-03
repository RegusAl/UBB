import unittest

from domain.entities import Serial, Client, Rating
from exceptions.exceptions import RatingAlreadyAssignedException
from repository.rating_repo import RatingInMemoryRepo, RatingRepoFile


class TestCaseRatingRepoInMemory(unittest.TestCase):
    def setUp(self) -> None:
        self.__repo = RatingInMemoryRepo()

    def test_store(self):
        show = Serial('SF123', 'See', 2019, 12)
        client = Client('1', 'Anda', 26)

        rating = Rating('SF123', '1', 3.8)

        self.__repo.store(rating)

        self.assertEqual(len(self.__repo.get_all()), 1)
        self.assertRaises(RatingAlreadyAssignedException, self.__repo.store, rating)

    def test_find(self):
        show1 = Serial('SF123', 'See', 2019, 12)
        show2 = Serial('D2437', 'Grey\'s Anatomy', 2005, 384)

        client = Client('1', 'Anda', 26)
        client2 = Client('2', 'Valeriu', 65)

        rating1 = Rating('SF123', '1', 3.8)
        rating2 = Rating('D2347', '1', 2.5)

        self.__repo.store(rating1)
        self.__repo.store(rating2)

        rating3 = Rating('SF123', '2', 4.2)

        self.assertEqual(self.__repo.find(rating1), rating1)
        self.assertIs(self.__repo.find(rating3), None)


class TestCaseRatingRepoFile(unittest.TestCase):
    def setUp(self) -> None:
        self.__repo = RatingRepoFile('test_ratings_repo.txt')

    def test_store(self):
        show = Serial('SF123', 'See', 2019, 12)
        client = Client('1', 'Anda', 26)

        rating = Rating('SF123', '1', 3.8)

        self.__repo.store(rating)

        self.assertEqual(len(self.__repo.get_all()), 1)
        self.assertRaises(RatingAlreadyAssignedException, self.__repo.store, rating)

    def test_find(self):
        show1 = Serial('SF123', 'See', 2019, 12)
        show2 = Serial('D2437', 'Grey\'s Anatomy', 2005, 384)

        client = Client('1', 'Anda', 26)
        client2 = Client('2', 'Valeriu', 65)

        rating1 = Rating('SF123', '1', 3.8)
        rating2 = Rating('D2347', '1', 2.5)

        self.__repo.store(rating1)
        self.__repo.store(rating2)

        rating3 = Rating('SF123', '2', 4.2)

        self.assertEqual(self.__repo.find(rating1), rating1)
        self.assertIs(self.__repo.find(rating3), None)

    def tearDown(self) -> None:
        self.__repo.delete_all()
