from erori.repo_error import RepoError
class RepoFilme:

    def __init__(self):
        self.__filme = [
            [7, "Jumanji", "Aventura"],
            [11, "Jurrasic Park", "Actiune"],
            [12, "Avatar", "Actiune"],
            [13, "Fast and Furious", "Actiune"],
            [15, "Rush Hour", "Comedie"]
        ]

    def adauga_film(self, film):
        '''
        Adauga un film in lista de filme
        :param film: filmul ce trebuie adaugat
        :type film: Film
        :return: -; lista de filme se modifica prin adaugarea filmului dat de utilizator
        '''
        for el in self.__filme:
            if el[0] == film[0]:
                raise RepoError("Film existent!")
        self.__filme.append(film)

    def afisare_filme(self):
        '''
        Returneaza lista de filme
        :return: lista de filme
        :rtype: lista
        '''
        return self.__filme

    def stergere_film(self, id):
        '''
        Sterge filmul in functie de id
        :param id: int
        :return: -; Copie in lista de filme toate filmele, fara filmul cu id-ul dat de utilizator
        '''
        lista_filme = []
        ok = False
        for el in self.__filme:
            if el[0] != id:
                lista_filme.append(el)
            if el[0] == id:
                ok = True
        if ok == False:
            raise RepoError("Film inexistent!")
        self.__filme = lista_filme.copy()

    def __len__(self):
        return len(self.__filme)

    def __str__(self):
       pass


