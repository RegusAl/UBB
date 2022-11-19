from domeniu.filme import get_id_film
from erori.repo_error import RepoError
class RepoFilme:

    def __init__(self):

        # lista de liste
        self.__filme = [
            [7, "Jumanji", "Aventura"],
            [11, "Jurrasic Park", "Actiune"],
            [12, "Avatar", "Actiune"],
            [13, "Fast and Furious", "Actiune"],
            [15, "Rush Hour", "Comedie"]
        ]

        # lista de dictionare
        # self.__filme = [
        #     {'id': 7, 'nume': 'Jumanji', 'gen': 'aventura'},
        #     {'id': 11, 'nume': 'Jurrasic Park', 'gen': 'Actiune'},
        #     {'id': 12, 'nume': 'Avatar', 'gen': 'Actiune'},
        #     {'id': 13, 'nume': 'Fast and Furious', 'gen': 'Actiune'},
        #     {'id': 15, 'nume': 'Rush Hour', 'gen': 'Comedie'}
        # ]

    ## Adauga
    def adauga_film(self, film):
        '''
        Adauga un film in lista de filme
        :param film: filmul ce trebuie adaugat
        :type film: Film
        :return: -; lista de filme se modifica prin adaugarea filmului dat de utilizator
        '''
        for el in self.__filme:
            if get_id_film(el) == get_id_film(film):
                raise RepoError("Film existent!")
        self.__filme.append(film)

    ## Afiseaza
    def afisare_filme(self):
        '''
        Returneaza lista de filme
        :return: lista de filme
        :rtype: lista
        '''
        return self.__filme

    ## Sterge
    def stergere_film(self, id):
        '''
        Sterge filmul in functie de id
        :param id: int
        :return: -; Copie in lista de filme toate filmele, fara filmul cu id-ul dat de utilizator
        '''
        lista_filme = []
        ok = False
        for el in self.__filme:
            if get_id_film(el) != id:
                lista_filme.append(el)
            if get_id_film(el) == id:
                ok = True
        if ok == False:
            raise RepoError("Film inexistent!")
        self.__filme = lista_filme.copy()

    def __len__(self):
        return len(self.__filme)

    def __str__(self):
       pass


