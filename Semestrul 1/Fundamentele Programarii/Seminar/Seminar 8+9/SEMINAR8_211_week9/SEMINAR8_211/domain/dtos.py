
class ClientShowRating:
    def __init__(self, nume_client, nume_serial, no_stars):
        # fields: nume client, nume serial, no. stars
        self.__nume_client = nume_client
        self.__nume_serial = nume_serial
        self.__no_stars = no_stars

    def getNumeClient(self):
        return self.__nume_client

    def getTitluSerial(self):
        return self.__nume_serial

    def getNoStars(self):
        return self.__no_stars

    def setNumeClient(self, value):
        self.__nume_client = value

    def setTitluSerial(self, value):
        self.__nume_serial = value

    def setNoStars(self, value):
        self.__no_stars = value


class ShowRatingInfo:

    def __init__(self, titlu_serial, initial_stars, initial_age):
        # Se va afișa titlul serialului, numărul de rating-uri,
        # avg_no_stars, și media de vârstă.
        self.__titlu_serial = titlu_serial
        self.__no_ratings = 1

        self.__total_age = initial_age
        self.__total_stars = initial_stars

        self.__avg_no_stars = 0
        self.__avg_age = 0

    def getTitluSerial(self):
        return self.__titlu_serial

    def getNoRatings(self):
        return self.__no_ratings

    def getAvgNoStars(self):
        return self.__avg_no_stars

    def getMedieVarsta(self):
        return self.__avg_age

    def increaseNoRatings(self):
        self.__no_ratings += 1

    def addToNoStars(self, value):
        self.__total_stars += value

    def addToAge(self, value):
        self.__total_age += value

    def compute_means(self):
        # initial version during the seminar not the best option
        # for one, the code doesn't really make sense when you read it


        # self.__avg_no_stars = self.__avg_no_stars / self.__no_ratings
        # self.__avg_age = self.__avg_age / self.__no_ratings

        # so we now have a field that holds total number of stars
        # and a field that holds sum of ages
        # increase these fields
        # and at the end divide by number of ratings

        self.__avg_no_stars = self.__total_stars / self.__no_ratings
        self.__avg_age = self.__total_age / self.__no_ratings
