class SantaVillageException(Exception):
    pass
class SearchException(SantaVillageException):
    def __init__(self, msg):
        self.__msg = msg

    def getMessage(self):
        return self.__msg

    def __str__(self):
        return 'Santa found an error with your request: ' + str(self.__msg)


class NoWorkshopsWithTypeException(SearchException):
    def __init__(self):
        SearchException.__init__(self, "Oh no! No workshops with this type.")

class NotEnoughElvesException(SearchException):
    def __init__(self):
        SearchException.__init__(self, "Uh-oh! Too few elves to fulfil your request...")

class RepositoryException(SantaVillageException):
    def __init__(self, msg):
        self.__msg = msg

    def getMessage(self):
        return self.__msg

    def __str__(self):
        return 'Santa found an error with your request: ' + str(self.__msg)

class NoWorkshopWithNameException(RepositoryException):
    def __init__(self):
        RepositoryException.__init__(self, "No workshop with that name found :(.")