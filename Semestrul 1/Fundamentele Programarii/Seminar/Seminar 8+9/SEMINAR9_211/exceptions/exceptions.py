class ShowManagerException(Exception):
    pass


class ValidationException(ShowManagerException):
    def __init__(self, msgs):
        """
        :param msgs: lista de mesaje de eroare
        :type msgs: msgs
        """
        self.__err_msgs = msgs

    def getMessages(self):
        return self.__err_msgs

    def __str__(self):
        return 'Validation Exception: ' + str(self.__err_msgs)


class RepositoryException(ShowManagerException):
    def __init__(self, msg):
        self.__msg = msg

    def getMessage(self):
        return self.__msg

    def __str__(self):
        return 'Repository Exception: ' + str(self.__msg)


class DuplicateIDException(RepositoryException):
    def __init__(self):
        RepositoryException.__init__(self, "ID duplicat.")


class RatingAlreadyAssignedException(RepositoryException):
    def __init__(self):
        RepositoryException.__init__(self, "Rating existent deja pentru serial si client dat.")


class ShowNotFoundException(RepositoryException):
    def __init__(self):
        RepositoryException.__init__(self, "Serialul nu a fost gasit.")


class RatingNotFoundException(RepositoryException):
    def __init__(self):
        RepositoryException.__init__(self, "Rating-ul nu a fost gasit.")


class ClientNotFoundException(RepositoryException):
    def __init__(self):
        RepositoryException.__init__(self, "Clientul nu a fost gasit.")


class NotEnoughRatingsException(ShowManagerException):
    def __init__(self):
        pass


class CorruptedFileException(ShowManagerException):
    def __init__(self):
        pass
