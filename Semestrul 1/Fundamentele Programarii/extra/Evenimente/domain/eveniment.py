class Eveniment:

    def __init__(self, data, ora, descriere):
        self.__data = data
        self.__ora = ora
        self.__descriere = descriere

    def get_data(self):
        '''
        Returneaza data
        :return: data (string)
        '''
        return self.__data

    def get_ora(self):
        '''
        Returneaza ora
        :return: ora (string)
        '''
        return self.__ora

    def get_descriere(self):
        '''
        Returneaza descrierea
        :return: descrierea (string)
        '''
        return self.__descriere

