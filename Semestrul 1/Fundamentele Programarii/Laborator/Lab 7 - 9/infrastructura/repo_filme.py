from domeniu.filme import Film
from erori.repo_error import RepoError

class RepoFilme:

    def __init__(self):
        self.__filme = []


        # lista de liste
        # self.__filme = [
        #     Film(1, 'Jumanji', 'Aventura'),
        #     Film(2, 'Fast and Furious', 'Actiune'),
        #     Film(3, 'Up', 'Comedie'),
        #     Film(4, 'Rush Hour', 'Comedie'),
        #     Film(5, 'Jurassic Park', 'Actiune'),
        #     Film(6, 'Top Gun', 'Aventura'),
        #     Film(7, 'Avatar', 'SF'),
        #     Film(8, 'Black Adam', 'Actiune'),
        #     Film(9, 'Gladiator', 'Istoric')
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
            if el.get_id_film() == film.get_id_film():
                raise RepoError("Film existent!")
        self.__filme.append(film)

    ## Afiseaza
    def get_all(self):
        '''
        Returneaza lista de filmefrom testare.teste import TesteFilme, TesteClienti
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

class RepoFilmeFile:

    def __init__(self, filename):
        self.__filename = filename

    def __load_from_file(self):
        '''
        Luam filmele din fisier
        :return: -
        '''
        try:
            f = open(self.__filename, 'r')
        except IOError:
            return
        lines = f.readlines()
        filme = []
        for line in lines:
            id_film, nume_film, gen_film = [token.strip() for token in line.split(';')]
            id_film = int(id_film)

            film = Film(id_film, nume_film, gen_film)
            filme.append(film)
        f.close()
        return filme

    def __save_to_file(self, filme):
        '''
        Salvam filmele in fisier
        :param filme: lista de filme ce trebuie salvata in fisier
        :return: -
        '''
        with open(self.__filename, 'w') as f:
            for film in filme:
                filme_strings = str(film.get_id_film()) + ';' + str(film.get_nume_film()) + ';' + str(film.get_gen_film()) + '\n'
                f.write(filme_strings)

    def adauga_film(self, film):
        '''
        Adauga un film pe care il incarca in fisier
        :param film: filmul ce trebuie incarcat in fisier
        :return: -
        '''
        filme = self.__load_from_file()
        if film in filme:
            raise RepoError("Film existent!")
        filme.append(film)
        self.__save_to_file(filme)

    def get_all(self):
        """
        Returneaza o lista cu toate filmele
        :rtype: lista
        """
        return self.__load_from_file()

    def stergere_film(self, id_film):
        '''
        Sterge filmul in functie de id
        :param id_film: int
        :return: -; Copie in lista de filme toate filmele, fara filmul cu id-ul dat de utilizator
        '''
        lista_filme = []
        ok = False
        for el in self.__load_from_file():
            if el.get_id_film() != id_film:
                lista_filme.append(el)
            if el.get_id_film()== id_film:
                ok = True
        if ok == False:
            raise RepoError("Film inexistent!")
        self.__save_to_file(lista_filme)