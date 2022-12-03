from domain.entities import Rating
from domain.validators import RatingValidator
from exceptions.exceptions import ShowNotFoundException, ClientNotFoundException, RatingAlreadyAssignedException, \
    ValidationException
from repository.client_repo import ClientFileRepo
from repository.rating_repo import RatingInMemoryRepo
from repository.show_repo import ShowFileRepo


class RatingService:
    def __init__(self, rating_repo, rating_val, show_repo, client_repo):
        self.__rating_repo = rating_repo
        self.__rating_val = rating_val
        self.__show_repo = show_repo
        self.__client_repo = client_repo

    def create_rating(self, show_id, client_id, no_stars):
        """
        Creeaza un rating
        :param show_id: id-ul show-ului evaluat
        :type show_id: str
        :param client_id: id-ul clientului care evalueaza
        :type client_id: str
        :param no_stars: numarul de stele acordate serialului (1-5)
        :type no_stars: float
        :return: rating-ul creat cu datele date
        :rtype: Rating
        :raises: ShowNotFoundException
                 ClientNotFoundException
                 ValidationException
                 RatingAlreadyAssignedException
        """
        show = self.__show_repo.find(show_id)
        if show is None:
            raise ShowNotFoundException()

        client = self.__client_repo.find(client_id)

        if client is None:
            raise ClientNotFoundException()

        rating = Rating(show, client, no_stars)
        self.__rating_val.validate(rating)
        self.__rating_repo.store(rating)
        return rating

    def get_all(self):
        return self.__rating_repo.get_all()

    def get_top_shows(self, client_id, n=3):
        """
        Returneaza primele 3 show-uri cu cele mai bune rating-uri pentru un client dat
        :param client_id: id-ul clientului
        :type client_id: str
        :param n: numarul de seriale de afisat (default 3)
        :type n: int
        :return: lista cu obiecte DTO ClientShow
        :rtype: list of ClientShow objects
        """
        all_ratings = self.__rating_repo.get_all()
        client_ratings = []
        # go through the all_ratings list and save the ratings of the client
        # with client id in client_ratings
        # then sort them
        # return the first n (3) (SEMINAR: we'll work with DTOs, lab homework - can return ratings)
        pass


def test_create_rating():
    show_repo = ShowFileRepo('test_shows_service.txt')
    client_repo = ClientFileRepo('test_clients_service.txt')

    rating_repo = RatingInMemoryRepo()
    rating_val = RatingValidator()

    test_srv = RatingService(rating_repo, rating_val, show_repo, client_repo)
    created_rating = test_srv.create_rating('C1001', '1', 3)

    assert (created_rating.getClient() == client_repo.find('1'))
    assert (created_rating.getSerial() == show_repo.find('C1001'))
    assert (created_rating.getNoStars() == 3)

    try:
        test_srv.create_rating('C1001', '1', 3.55)
        assert False
    except RatingAlreadyAssignedException:
        assert True

    try:
        test_srv.create_rating('462873', '1', 3.7)
        assert False
    except ShowNotFoundException:
        assert True

    try:
        test_srv.create_rating('C1001', '8632', 4.8)
        assert False
    except ClientNotFoundException:
        assert True

    try:
        test_srv.create_rating('F2638', '5', 8)
        assert False
    except ValidationException:
        assert True
