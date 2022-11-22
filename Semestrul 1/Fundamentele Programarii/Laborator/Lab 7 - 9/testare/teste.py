from domeniu.clienti import Client
from domeniu.filme import Film

## Teste filme
class TesteFilme:
    def __init__(self, validator_filme, service_filme, repo_filme):
        self.__validator_filme = validator_filme
        self.__service_filme = service_filme
        self.__repo_filme = repo_filme

    def test_adaugare(self):
        lista = []
        film = Film(1, "Jumanji", "Aventura")
        lista.append(film)
        assert (lista[0] == film)
        assert (film.get_id_film() == 1)
        assert (film.get_nume_film() == "Jumanji")
        assert (film.get_gen_film() == "Aventura")

## Teste Clienti
class TesteClienti:
    def __init__(self, validator_clienti, service_clienti, repo_clienti):
        self.__validator_clienti = validator_clienti
        self.__service_clienti = service_clienti
        self.__repo_clienti = repo_clienti

    def test_adaugare(self):
        lista = []
        client = Client(89, "Mihai Alexandru", 50307894626)
        lista.append(client)
        assert (lista[0] == client)
        assert (client.get_id_client() == 89)
        assert (client.get_nume_client() == "Mihai Alexandru")
        assert (client.get_cnp_client() == 50307894626)