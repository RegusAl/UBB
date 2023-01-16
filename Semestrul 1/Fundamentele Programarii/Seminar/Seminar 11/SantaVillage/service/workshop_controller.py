from domain.workshop_evaluation import WorkshopEvaluation
from exceptions.exceptions import NoWorkshopsWithTypeException, NotEnoughElvesException


class WorkshopController:
    def __init__(self, workshop_repo):
        self.__workshop_repo = workshop_repo

    def get_all_with_type_and_elves(self, product_type, no_elves):
        """
        Get all workshops with a given product type and with a number of elves greater than the given number
        :param product_type: the product type
        :type product_type: str
        :param no_elves: the number of elves
        :type no_elves: int
        :return: all workshops that make products of the given type and have a greater number of elves than that given
        :rtype: list of Workshop objects
        :raises: NoWorkshopWithTypeException if no workshop with given type exists
                 NotEnoughElvesException if none of the workshops with the given type has a sufficient number of elves
        """
        all_workshops = self.get_all()
        workshops_with_type = [workshop for workshop in all_workshops if
                               product_type in workshop.get_product_type()]

        # if no workshops that make the given type are found, the requirement says
        # to throw an exception

        if len(workshops_with_type) == 0:
            raise NoWorkshopsWithTypeException()

        workshops_with_elves = [workshop for workshop in workshops_with_type if
                                workshop.get_number_of_elves() >= no_elves]

        # if none of the workshops with the given type have enough elves working,
        # then we throw an exception
        if len(workshops_with_elves) == 0:
            raise NotEnoughElvesException()

        return workshops_with_elves

    def evaluate_workshop(self, name, number_of_days):
        """
        Evaluate a workshop
        :param name: name of the workshop
        :type name: str
        :param number_of_days: number of days for evaluation
        :type number_of_days: int
        :return: evaluation of the given workshop
        :rtype: WorkshopEvaluation object
        :raises NoWorkshopWithNameException exception if a workshop with a given name cannot be found
        """
        workshop = self.__workshop_repo.find_by_name(name)
        evaluation = WorkshopEvaluation(workshop, number_of_days)
        return evaluation

    def get_all(self):
        """
        Get all workshops
        :return: a list of all workshops
        :rtype: list of Workshop objects
        """
        return self.__workshop_repo.get_all()
