from domain.dtos import ClientShowRating, ShowRatingInfo
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
        client = self.__client_repo.find(client_id)

        if client is None:
            raise ClientNotFoundException()

        all_ratings = self.__rating_repo.get_all()
        client_ratings = []

        for rating in all_ratings:
            if rating.getClient().getId() == client_id:
                client_show_r = ClientShowRating(rating.getClient().getNume(), rating.getSerial().getTitle(),
                                                 rating.getNoStars())
                client_ratings.append(client_show_r)

        # handle the case when we don't have enough ratings - either proceed
        # and return what we have
        # or throw an exception
        client_ratings = sorted(client_ratings, key=lambda x: x.getNoStars(), reverse=True)
        client_ratings = client_ratings[:n]

        return client_ratings

    def get_ratings_info(self):
        """
        Calculeaza numarul de rating-uri, avg. no. stars si media de varsta pentru toate serialele
        :return: lista de obiecte DTO care contin informatia necesara
        :rtype: list of ShowRatingInfo objects
        """
        all_ratings = self.__rating_repo.get_all()

        # {show_id: DTO}
        shows_ratings = {}

        for rating in all_ratings:
            if rating.getSerial().getId() not in shows_ratings:
                dto = ShowRatingInfo(rating.getSerial().getTitle(), rating.getNoStars(),
                                     rating.getClient().getVarsta())
                shows_ratings[rating.getSerial().getId()] = dto

            else:
                shows_ratings[rating.getSerial().getId()].increaseNoRatings()
                shows_ratings[rating.getSerial().getId()].addToNoStars(rating.getNoStars())
                shows_ratings[rating.getSerial().getId()].addToAge(rating.getClient().getVarsta())

        for show_id, show_rating in shows_ratings.items():
            show_rating.compute_means()

        return list(shows_ratings.values())


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


def test_get_top_shows():
    show_repo = ShowFileRepo('test_shows_service.txt')
    client_repo = ClientFileRepo('test_clients_service.txt')

    rating_repo = RatingInMemoryRepo()
    rating_val = RatingValidator()

    test_srv = RatingService(rating_repo, rating_val, show_repo, client_repo)
    _ = test_srv.create_rating('C1001', '1', 3)
    _ = test_srv.create_rating('F1001', '1', 3.4)
    _ = test_srv.create_rating('SF1643', '1', 4.25)
    _ = test_srv.create_rating('D2376', '1', 3.55)
    _ = test_srv.create_rating('D3246', '1', 2)

    client_ratings = test_srv.get_top_shows('1')
    # sorted by rating
    assert (len(client_ratings) == 3)
    assert (client_ratings[0].getNoStars() == 4.25)
    assert (client_ratings[0].getTitluSerial() == 'The X-Files')

    assert (client_ratings[1].getNoStars() == 3.55)
    assert (client_ratings[1].getTitluSerial() == 'Outer Banks')

    assert (client_ratings[2].getNoStars() == 3.4)
    assert (client_ratings[2].getTitluSerial() == 'Arrow')


def test_get_ratings_info():
    show_repo = ShowFileRepo('test_shows_service.txt')
    client_repo = ClientFileRepo('test_clients_service.txt')

    rating_repo = RatingInMemoryRepo()
    rating_val = RatingValidator()

    test_srv = RatingService(rating_repo, rating_val, show_repo, client_repo)

    # C1001 is Superstore
    _ = test_srv.create_rating('C1001', '1', 3)
    _ = test_srv.create_rating('C1001', '2', 4)
    _ = test_srv.create_rating('C1001', '3', 5)

    # F2638 is The Magicians
    _ = test_srv.create_rating('F2638', '1', 3.6)
    _ = test_srv.create_rating('F2638', '2', 3.4)

    # SF1643 is The X-Files
    _ = test_srv.create_rating('SF1643', '1', 4.25)

    show_ratings = test_srv.get_ratings_info()

    # list not sorted
    # let's sort it in a way that we are sure what we are checking

    show_ratings = sorted(show_ratings, key=lambda x: x.getTitluSerial())

    # we have 3 shows with at least 1 rating
    assert (len(show_ratings) == 3)

    assert (show_ratings[0].getTitluSerial() == 'Superstore')
    assert (show_ratings[0].getNoRatings() == 3)
    assert (show_ratings[0].getAvgNoStars() == 4)
    assert (show_ratings[0].getMedieVarsta() == 30)

    assert (show_ratings[1].getTitluSerial() == 'The Magicians')
    assert (show_ratings[1].getNoRatings() == 2)
    assert (show_ratings[1].getAvgNoStars() == 3.5)
    assert (show_ratings[1].getMedieVarsta() == 35)

    assert (show_ratings[2].getTitluSerial() == 'The X-Files')
    assert (show_ratings[2].getNoRatings() == 1)
    assert (show_ratings[2].getAvgNoStars() == 4.25)
    assert (show_ratings[2].getMedieVarsta() == 28)
