from domain.dtos import ClientShowRating
from domain.entities import Rating
from exceptions.exceptions import RatingAlreadyAssignedException, CorruptedFileException


class RatingInMemoryRepo:
    def __init__(self):
        self.__ratings = []

    def find(self, r):
        """
        Cauta rating in lista de evaluari
        :param r: rating-ul cautat
        :type r: Rating
        :return: rating-ul cautat daca exista in lista, None altfel
        :rtype: Rating
        """
        for rating in self.__ratings:
            if r == rating:
                return rating
        return None

    def store(self, rating):
        """
        Adauga o evaluare
        :param rating: evaluarea de adaugat
        :type rating: Rating
        :return: -; se adauga rating la lista de evaluari
        :rtype: -
        :raises: RatingAlreadyAssignedException daca exista deja rating pentru serialul si ratingul dat
        """
        r = self.find(rating)
        if r is not None:
            raise RatingAlreadyAssignedException()
        self.__ratings.append(rating)

    def get_all(self):
        """
        Returneaza o lista cu toate evaluarile disponibile
        :return: lista cu evaluarile disponibile
        :rtype: list of Rating objects
        """
        return self.__ratings

    def delete_all(self):
        self.__ratings = []


class RatingRepoFile(RatingInMemoryRepo):
    def __init__(self, filename):
        RatingInMemoryRepo.__init__(self)
        self.__filename = filename
        self.__load_from_file()

    def __load_from_file(self):
        try:
            f = open(self.__filename, 'r')
            # f = io.open(self.__filename, mode='r', encoding='utf-8')
        except IOError:
            raise CorruptedFileException()

        lines = f.readlines()
        for line in lines:
            show_id, rating_id, no_stars = [token.strip() for token in line.split(';')]
            a = Rating(show_id, rating_id, float(no_stars))
            RatingInMemoryRepo.store(self, a)
        f.close()

    def __save_to_file(self):
        ratings_list = RatingInMemoryRepo.get_all(self)
        with open(self.__filename, 'w') as f:
            for rating in ratings_list:
                rating_string = str(rating.getSerialId()) + ';' + str(rating.getClientId()) + ';' + str(
                    rating.getNoStars()) + '\n'
                f.write(rating_string)

    def find(self, r):
        """
        Cauta rating in lista de evaluari
        :param r: rating-ul cautat
        :type r: Rating
        :return: rating-ul cautat daca exista in lista, None altfel
        :rtype: Rating
        """
        return RatingInMemoryRepo.find(self, r)

    def store(self, rating):
        """
        Adauga o evaluare
        :param rating: evaluarea de adaugat
        :type rating: Rating
        :return: -; se adauga rating la lista de evaluari
        :rtype: -
        :raises: RatingAlreadyAssignedException daca exista deja rating pentru serialul si ratingul dat
        """
        RatingInMemoryRepo.store(self, rating)
        self.__save_to_file()

    def get_all(self):
        """
        Returneaza o lista cu toate evaluarile disponibile
        :return: lista cu evaluarile disponibile
        :rtype: list of Rating objects
        """
        return RatingInMemoryRepo.get_all(self)

    def delete_all(self):
        RatingInMemoryRepo.delete_all(self)
        self.__save_to_file()

    def get_all_for_client(self, client_id):
        """
        Gaseste toate rating-urile aferente unui client dat
        :param client_id: id-ul clientului
        :type client_id:str
        :return: lista cu obiecte ClientShowRating care contin informatiile
                  necesare (id client, id serial, no.stars)
        :rtype: list of ClientShowRating objects
        """
        all_ratings = self.get_all()
        client_ratings = []

        for rating in all_ratings:
            if rating.getClientId() == client_id:
                client_show_r = ClientShowRating(rating.getClientId(), rating.getSerialId(),
                                                 rating.getNoStars())
                client_ratings.append(client_show_r)

        return client_ratings

    def test_get_all_for_client(self):
        pass
