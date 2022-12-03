import unittest

from domain.validators import RatingValidator
from exceptions.exceptions import RatingAlreadyAssignedException, ShowNotFoundException, ClientNotFoundException, \
    ValidationException
from repository.client_repo import ClientFileRepo
from repository.rating_repo import RatingRepoFile
from repository.show_repo import ShowFileRepo
from service.rating_service import RatingService


class TestCaseRatingService(unittest.TestCase):
    def setUp(self) -> None:
        show_repo = ShowFileRepo('test_shows_service.txt')
        client_repo = ClientFileRepo('test_clients_service.txt')

        self.__initialize_ratings_file()

        rating_repo = RatingRepoFile('test_ratings_service.txt')
        rating_val = RatingValidator()

        self.__srv = RatingService(rating_repo, rating_val, show_repo, client_repo)

    def __initialize_ratings_file(self):
        with open("original_ratings.txt", 'r') as f:
            with open("test_ratings_service.txt", "w") as f1:
                f1.write(f.read())

    def test_create_rating(self):
        created_rating = self.__srv.create_rating('C1001', '2', 3)

        self.assertEqual(created_rating.getClientId(), '2')
        self.assertEqual(created_rating.getSerialId(), 'C1001')
        self.assertEqual(created_rating.getNoStars(), 3)

        self.assertRaises(RatingAlreadyAssignedException, self.__srv.create_rating, 'C1001', '2', 3.55)
        self.assertRaises(ShowNotFoundException, self.__srv.create_rating, '462873', '1', 3.7)
        self.assertRaises(ClientNotFoundException, self.__srv.create_rating, 'C1001', '8632', 4.8)
        self.assertRaises(ValidationException, self.__srv.create_rating, 'F2638', '5', 8)

    def test_get_top_shows(self):
        # client with id 1 has the following ratings (in test_ratings_service.txt):
        # C1001;1;3.5
        # F1001;1;3.0
        # C1002;1;1.8
        # D1854;1;2.97
        # F2638;1;4.0
        # D1211;1;1.48
        # D1372;1;3.6
        # SF1643;1;4.7

        # top 3: SF1643 (The X-Files), F2638 (The Magicians), D1372 (ER)

        client_ratings = self.__srv.get_top_shows('1')
        # sorted by rating
        self.assertEqual(len(client_ratings) , 3)
        self.assertEqual(client_ratings[0].getNoStars() , 4.7)
        self.assertEqual(client_ratings[0].getTitluSerial() , 'The X-Files')

        self.assertEqual(client_ratings[1].getNoStars() , 4.0)
        self.assertEqual(client_ratings[1].getTitluSerial() , 'The Magicians')

        self.assertEqual(client_ratings[2].getNoStars() , 3.6)
        self.assertEqual(client_ratings[2].getTitluSerial() , 'ER')

    def test_get_ratings_info(self):
        #not implemented in this version
        pass
