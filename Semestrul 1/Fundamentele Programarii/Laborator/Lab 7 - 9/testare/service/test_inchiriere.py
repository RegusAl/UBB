import unittest

from infrastructura.repo_clienti import RepoClienti
from infrastructura.repo_filme import RepoFilme
from infrastructura.repo_inchiriere import RepoInchiriere
from services.service_clienti import ServiceClienti
from services.service_filme import ServiceFilme
from services.service_inchiriere import ServiceInchiriere
from validare.validator_clienti import ValidatorClienti
from validare.validator_filme import ValidatorFilme

class TestCaseInchiriereService(unittest.TestCase):

    def setUp(self) -> None:
        validator_filme = ValidatorFilme()
        validator_clienti = ValidatorClienti()
        repo_filme = RepoFilme()
        repo_clienti = RepoClienti()
        repo_inchiriere = RepoInchiriere()
        self.service_filme = ServiceFilme(validator_filme, repo_filme, repo_inchiriere)
        self.service_clienti = ServiceClienti(validator_clienti, repo_clienti, repo_inchiriere)
        self.__srv = ServiceInchiriere(validator_clienti, validator_filme, repo_clienti, repo_filme, repo_inchiriere, self.service_clienti, self.service_filme)

    def test_inchiriere(self):
        film = self.service_filme.adauga_film(1, "Jumanji", "Aventura")
        client = self.service_clienti.adauga_client(1, "Gigel", 1234556789102)
        inchiriere = self.__srv.inchiriere(film.get_id_film(), client.get_id_client())
        self.assertTrue(inchiriere.get_client() == 1)
        self.assertTrue(inchiriere.get_film() == 1)

    def test_afisare_inchiriere(self):
        film = self.service_filme.adauga_film(1, "Jumanji", "Aventura")
        client = self.service_clienti.adauga_client(1, "Gigel", 1234556789102)
        lista = []
        inchiriere = self.__srv.inchiriere(film.get_id_film(), client.get_id_client())
        lista.append(inchiriere)
        lista = self.__srv.afisare_inchiriere()
        assert (len(lista) == 1)

    def test_returnare(self):
        film = self.service_filme.adauga_film(1, "Jumanji", "Aventura")
        client = self.service_clienti.adauga_client(1, "Gigel", 1234556789102)
        lista = []
        inchiriere = self.__srv.inchiriere(film.get_id_film(), client.get_id_client())
        lista.append(inchiriere)
        lista = self.__srv.afisare_inchiriere()
        assert (len(lista) == 1)
        self.__srv.returnare(1, 1)
        lista = self.__srv.afisare_inchiriere()
        assert (len(lista) == 0)
