from domeniu.inchiriere import Inchiriere
from utils.sortari import bubble_sort, shell_sort


class ServiceInchiriere:

    def __init__(self, validator_clienti, validator_filme, repo_clienti, repo_filme, repo_inchiriere, service_clienti, service_filme):
        self.__validator_clienti = validator_clienti
        self.__validator_filme = validator_filme
        self.__repo_clienti = repo_clienti
        self.__repo_filme = repo_filme
        self.__repo_inchiriere = repo_inchiriere
        self.__service_clienti = service_clienti
        self.__service_filme = service_filme

    def inchiriere(self, id_client, id_film):
        film = self.__service_filme.cauta_film_dupa_id(id_film)
        client = self.__service_clienti.cauta_client_dupa_id(id_client)
        self.__validator_filme.valideaza(film)
        self.__validator_clienti.valideaza(client)
        inchiriere = Inchiriere(id_client, id_film)
        self.__repo_inchiriere.adauga_inchiriere(inchiriere)
        return inchiriere

    def afisare_inchiriere(self):
        return self.__repo_inchiriere.afisare()

    def returnare(self, id_client, id_film):
        self.__repo_inchiriere.returnare(id_client, id_film)

    def sortare_nume(self):
        lista_clienti = []
        for el in self.__repo_inchiriere.afisare():
            client = self.__service_clienti.cauta_client_dupa_id(el.get_client())
            if client.get_nume_client() not in lista_clienti:
                lista_clienti.append(client.get_nume_client())
        #lista_clienti.sort()
        bubble_sort(lista_clienti)
        return lista_clienti

    def sortare_numar(self):
        lista_clienti = []
        for el in self.__repo_inchiriere.afisare():
            nr_film = 0
            client_id = self.__service_clienti.cauta_client_dupa_id(el.get_client()).get_nume_client()
            lista_filme = []
            for element in self.__repo_inchiriere.afisare():
                id = self.__service_clienti.cauta_client_dupa_id(element.get_client()).get_nume_client()
                if client_id == id:
                    nr_film += 1
                    film = self.__service_filme.cauta_film_dupa_id(element.get_film()).get_nume_film()
                    lista_filme.append(film)
            if [nr_film, client_id, lista_filme] not in lista_clienti:
                lista_clienti.append([nr_film, client_id, lista_filme])
        #lista_clienti.sort(reverse=True)
        bubble_sort(lista_clienti, reverse=True)
        return lista_clienti

    def filme_inchiriate(self):
        lista_filme = []
        for el in self.__repo_inchiriere.afisare():
            nr_film = 0
            film_id = self.__service_filme.cauta_film_dupa_id(el.get_film()).get_nume_film()
            for element in self.__repo_inchiriere.afisare():
                id = self.__service_filme.cauta_film_dupa_id(element.get_film()).get_nume_film()
                if film_id == id:
                    nr_film += 1
            if [nr_film, film_id] not in lista_filme:
                lista_filme.append([nr_film, film_id])
        #lista_filme.sort(reverse=True)
        shell_sort(lista_filme, reverse = True)
        return lista_filme

    def filme_inchiriate_30(self):
        lista = self.sortare_numar()
        index = len(lista)
        index *= (3/10)
        lista30 = []
        i = 0
        while index>=0:
            lista30.append(lista[i])
            i += 1
            index -= 1
        return lista30

    def sortare_gen(self):
        lista_clienti = []
        for el in self.__repo_inchiriere.afisare():
            nr_film = 0
            client_id = self.__service_clienti.cauta_client_dupa_id(el.get_client()).get_nume_client()
            lista_finala = []
            lista_gen_filme = []
            lista_nr_gen_filme = []
            for element in self.__repo_inchiriere.afisare():
                id = self.__service_clienti.cauta_client_dupa_id(element.get_client()).get_nume_client()
                if client_id == id:
                    nr_film += 1
                    gen_film = self.__service_filme.cauta_film_dupa_id(element.get_film()).get_gen_film()
                    lista_gen_filme.append(gen_film)
            for gen in lista_gen_filme:
                nr_gen = 0
                for el in lista_gen_filme:
                    if gen==el:
                        nr_gen += 1
                lista_nr_gen_filme.append(nr_gen)
            i = 0
            for i in range(len(lista_gen_filme)):
                if [lista_gen_filme[i], lista_nr_gen_filme[i]] not in lista_finala:
                    lista_finala.append([lista_gen_filme[i], lista_nr_gen_filme[i]])
            if [nr_film, client_id, lista_finala] not in lista_clienti:
                lista_clienti.append([nr_film, client_id, lista_finala])
        #lista_clienti.sort(reverse=True)
        shell_sort(lista_clienti, reverse = True)
        return lista_clienti

