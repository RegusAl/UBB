from domeniu.filme import Film
class ServiceFilme:

    def __init__(self, validator_filme, repo_filme):
        self.__validator_filme = validator_filme
        self.__repo_filme = repo_filme

    def adauga_film(self, id_film, nume_film, gen_film):
        '''
        Adauga un film
        :param: id_film: id-ul filmului
        :type: int
        :param nume_film: numele filmului
        :type: string
        :param gen_film: genul filmului
        :type: string
        :return: - ; apelam functii din Repo si Validator
        :raises: Error daca filmul are date invalide
        '''
        film = Film(id_film, nume_film, gen_film).creare_film()
        # print(film)
        self.__validator_filme.valideaza(film)
        self.__repo_filme.adauga_film(film)

    def afisare_filme(self):
        '''
        Afiseaza filmele
        :return: lista de filme
        :rtype: lista de obiecte
        '''
        return self.__repo_filme.afisare_filme()

    def sterge_film_dupa_id(self, id_film):
        '''
        Sterge film in functie de id-ul primit prin parametru
        :param: id_film: id-ul filmului
        :type: int
        :return: -
        '''
        self.__repo_filme.stergere_film(id_film)
