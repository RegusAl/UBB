from domain.entities import Workshop
from exceptions.exceptions import NoWorkshopWithNameException


class WorkShopRepo:
    def __init__(self, filename):
        self.__filename = filename

    def __load_from_file(self):
        """
        Loads workshops from file
        :return: list of workshops that were loaded from file
        :rtype: list of Workshop objects
        """
        f = open(self.__filename, 'r', encoding='utf-8')
        lines = [line.strip() for line in f.readlines() if line.strip() != '']
        all_workshops = []
        for line in lines:
            name, location, product_type, number_of_elves = [item.strip() for item in line.split(';') if
                                                             item.strip() != '']
            w = Workshop(name, location, product_type, int(number_of_elves))
            all_workshops.append(w)

        f.close()
        return all_workshops

    def find_by_name(self, name):
        """
        Find a workshop based on name
        :param name: the name of the workshop
        :type name: str
        :return: the workshop with the given name
        :rtype: Workshop
        :raises: NoWorkshopWithNameException exception if a workshop with the given name is not found
        """
        all_workshops = self.__load_from_file()
        for workshop in all_workshops:
            if workshop.get_name() == name:
                return workshop
        raise NoWorkshopWithNameException()

    def get_all(self):
        """
        Get all workshops
        :return: a list of all workshops
        :rtype: list of Workshop objects
        """
        return self.__load_from_file()

