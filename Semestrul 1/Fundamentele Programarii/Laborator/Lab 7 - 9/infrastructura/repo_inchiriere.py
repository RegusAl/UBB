class RepoInchiriere:

    def __init__(self):
        self.__inchirieri = [
            [1, 7],
            [1, 11],
            [2, 13],
            [3, 15]
        ]

    def adauga_inchiriere(self, id_client, id_film):
        self.__inchirieri.append([id_client, id_film])

    def afisare(self):
        return self.__inchirieri

    def stergere_dupa_id(self, id, index):
        lista_inchirieri = []
        for el in self.__inchirieri:
            if el[index] != id:
                lista_inchirieri.append(el)
        self.__inchirieri = lista_inchirieri.copy()

    def returnare(self, id_client, id_film):
        lista_inchirieri = []
        for el in self.__inchirieri:
            if el[0] != id_client or el[1] != id_film:
                lista_inchirieri.append(el)
        self.__inchirieri = lista_inchirieri.copy()

