from domain.entities import Serial, Client, Rating
from exceptions.exceptions import RatingAlreadyAssignedException


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
        :raises: RatingAlreadyAssignedException daca exista deja rating pentru serialul si clientul dat
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


def test_store():
    show = Serial('SF123', 'See', 2019, 12)
    client = Client('1', 'Anda', 26)

    rating = Rating(show, client, 3.8)

    test_repo = RatingInMemoryRepo()
    test_repo.store(rating)

    assert (len(test_repo.get_all()) == 1)
    try:
        test_repo.store(rating)
        assert False
    except RatingAlreadyAssignedException:
        assert True