from domeniu.filme import Film
from erori.repo_error import RepoError
class RepoFilme:

    def __init__(self):

        # lista de liste
        self.__filme = [
            Film(1, 'Jumanji', 'Aventura'),
            Film(2, 'Fast and Furious', 'Actiune'),
            Film(3, 'Up', 'Comedie'),
            Film(4, 'Rush Hour', 'Comedie')
        ]

    ## Adauga
    def adauga_film(self, film):
        '''
        Adauga un film in lista de filme
        :param film: filmul ce trebuie adaugat
        :type film: Film
        :return: -; lista de filme se modifica prin adaugarea filmului dat de utilizator
        '''
        for el in self.__filme:
            if el.get_id_film() == film.get_id_film():
                raise RepoError("Film existent!")
        self.__filme.append(film)

    ## Afiseaza
    def afisare_filme(self):
        '''
        Returneaza lista de filme
        :return: lista de filme
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
            if el.get_id_film() != id:
                lista_filme.append(el)
            if el.get_id_film()== id:
                ok = True
        if ok == False:
            raise RepoError("Film inexistent!")
        self.__filme = lista_filme.copy()

    def __len__(self):
        return len(self.__filme)

    def __str__(self):
       pass


