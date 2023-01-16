from domain.entities import Workshop


class WorkshopEvaluation:
    """
    Class to evaluate a given workshop
    """

    def __init__(self, workshop: Workshop, number_of_days: int):
        self.__workshop = workshop
        self.__number_of_days = number_of_days
        self.__min_products, self.__max_products = self.__compute_production_estimate()

    def get_workshop(self):
        return self.__workshop

    def get_number_of_days(self):
        return self.__number_of_days

    def get_min_products(self):
        return self.__min_products

    def get_max_products(self):
        return self.__max_products

    def get_street_name(self):
        """
        Returns the street name for the workshop
        :return: street name
        :rtype: str
        """
        village, street_name, location = self.__workshop.get_location().split(',')
        return street_name.strip()

    def __compute_production_estimate(self):
        """
        Compute the production estimate (min and max)
        :return:  min_production, max_production (int)
        """
        return self.__workshop.get_number_of_elves() * 10 * self.__number_of_days, self.__workshop.get_number_of_elves() * 15 * self.__number_of_days

    def __str__(self):
        return "In the workshop " + self.__workshop.get_name() + " on " + self.get_street_name() + " where " + str(
            self.__workshop.get_number_of_elves()) + " hardworking elves work, this many products can be processed: minimum " + str(
            self.__min_products) + " and maximum: " + str(self.__max_products) + '.'
