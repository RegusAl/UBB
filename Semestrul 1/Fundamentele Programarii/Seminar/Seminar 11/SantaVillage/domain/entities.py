class Workshop:
    def __init__(self, name, location, product_type, number_of_elves):
        self.__name = name
        self.__location = location
        self.__product_type = product_type
        self.__number_of_elves = number_of_elves

    def get_name(self):
        return self.__name

    def get_location(self):
        return self.__location

    def get_product_type(self):
        return self.__product_type

    def get_number_of_elves(self):
        return self.__number_of_elves

    def set_name(self, value):
        self.__name = value

    def set_location(self, value):
        self.__location = value

    def set_product_type(self, value):
        self.__product_type = value

    def set_number_of_elves(self, value):
        self.__number_of_elves = value

    def __eq__(self, other):
        """
        Two workshops are considered equal if they have the same name
        """
        if other.get_name() == self.__name:
            return True
        return False

    def __str__(self):
        return "Name: " + str(self.__name) + ' | Location: ' + str(self.__location) + '| Product type: ' + str(
            self.__product_type) + ' | Number of elves working in the shop: ' + str(self.__number_of_elves)
