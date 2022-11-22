from domeniu.inchiriere import Inchiriere
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

    def afisare_inchiriere(self):
        return self.__repo_inchiriere.afisare()

    def returnare(self, id_client, id_film):
        self.__repo_inchiriere.returnare(id_client, id_film)