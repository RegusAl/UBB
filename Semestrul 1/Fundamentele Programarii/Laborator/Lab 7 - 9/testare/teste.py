from domeniu.clienti import Client, get_id_client, get_nume_client, get_cnp_client
from domeniu.filme import Film, get_id_film, get_gen_film, get_nume_film

## Teste filme
class TesteFilme:
    def __init__(self, validator_filme, service_filme, repo_filme):
        self.__validator_filme = validator_filme
        self.__service_filme = service_filme
        self.__repo_filme = repo_filme

    def test_adaugare(self):
        lista = []
        film = Film(1, "Jumanji", "Aventura").creare_film()
        lista.append(film)
        assert (lista[0] == film)
        assert (get_id_film(film) == 1)
        assert (get_nume_film(film) == "Jumanji")
        assert (get_gen_film(film) == "Aventura")

## Teste Clienti
class TesteClienti:
    def __init__(self, validator_clienti, service_clienti, repo_clienti):
        self.__validator_clienti = validator_clienti
        self.__service_clienti = service_clienti
        self.__repo_clienti = repo_clienti

    def test_adaugare(self):
        lista = []
        client = Client(89, "Mihai Alexandru", 50307894626).creare_client()
        lista.append(client)
        assert (lista[0] == client)
        assert (get_id_client(client) == 89)
        assert (get_nume_client(client) == "Mihai Alexandru")
        assert (get_cnp_client(client) == 50307894626)