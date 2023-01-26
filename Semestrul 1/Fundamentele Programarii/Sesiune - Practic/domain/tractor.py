class Tractor:

    def __init__(self, id, denumire, pret, model, data):
        '''
        initializare obiect de tip: Tractor
        :param id: id-ul tractorului
        :param denumire: denumirea tractorului
        :param pret: pretul tractorului
        :param model: modelul tractorului
        :param data: data la care expira revizia tractorului
        '''
        self.__id = id
        self.__denumire = denumire
        self.__pret = pret
        self.__model = model
        self.__data = data

    def get_id(self):
        '''
        :return: id-ul tractorului
        '''
        return self.__id

    def get_denumire(self):
        '''
        :return: denumirea tractorului
        '''
        return self.__denumire

    def get_pret(self):
        '''
        :return: pretul tractorului
        '''
        return self.__pret

    def get_model(self):
        '''
        :return: modelul tractorului
        '''
        return self.__model

    def get_data(self):
        '''
        :return: data tractorului
        '''
        return self.__data

    def set_denumire(self):
        '''
        Seteaza denumirea tractorului
        :return: denumirea tractorului cu "*"
        '''
        self.__denumire = "*" + self.__denumire