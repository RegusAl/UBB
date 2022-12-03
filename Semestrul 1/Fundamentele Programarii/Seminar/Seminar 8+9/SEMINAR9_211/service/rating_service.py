from domain.entities import Rating
from exceptions.exceptions import ShowNotFoundException, ClientNotFoundException


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

        rating = Rating(show_id, client_id, no_stars)
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
        :return: lista cu obiecte DTO ClientShowRating
        :rtype: list of ClientShowRating objects
        """
        client = self.__client_repo.find(client_id)

        if client is None:
            raise ClientNotFoundException()

        client_ratings = self.__rating_repo.get_all_for_client(client_id)

        client_ratings = sorted(client_ratings, key=lambda x: x.getNoStars(), reverse=True)
        client_ratings = client_ratings[:n]

        for client_rating in client_ratings:
            client_rating.setNumeClient(client.getNume())
            serial = self.__show_repo.find(client_rating.getShowId())
            client_rating.setTitluSerial(serial.getTitle())

        return client_ratings

    def get_ratings_info(self):
        """
        Calculeaza numarul de rating-uri, avg. no. stars si media de varsta pentru toate serialele
        :return: lista de obiecte DTO care contin informatia necesara
        :rtype: list of ShowRatingInfo objects
        """
        #similar cu primul raport
        pass
