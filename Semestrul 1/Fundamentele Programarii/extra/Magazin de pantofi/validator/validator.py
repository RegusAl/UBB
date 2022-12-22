class Validator():

    def __init__(self):
       pass
class RepoError(Exception):

    def __init__(self, message):
        self.__message = message