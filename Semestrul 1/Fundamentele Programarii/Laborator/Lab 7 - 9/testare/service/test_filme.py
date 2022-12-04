import unittest

from domeniu.filme import Film
from erori.repo_error import RepoError
from infrastructura.repo_filme import RepoFilme
from infrastructura.repo_inchiriere import RepoInchiriere
from services.service_filme import ServiceFilme
from validare.validator_filme import ValidatorFilme


class TestCaseFilmeService(unittest.TestCase):

    def setUp(self) -> None:
        repo_filme = RepoFilme()
        repo_inchiriere = RepoInchiriere()
        validator = ValidatorFilme()
        self.__srv = ServiceFilme(validator, repo_filme, repo_inchiriere)

    def test_adaugare_film(self):
        film = self.__srv.adauga_film(1, "Jumanji", "Aventura")
        assert (film.get_id_film() == 1)
        assert (film.get_nume_film() == "Jumanji")
        assert (film.get_gen_film() == "Aventura")

    def test_afisare_filme(self):
        lista_filme = []
        film  = self.__srv.adauga_film(1, "Jumanji", "Aventura")
        lista_filme.append(film)
        assert (len(lista_filme) == 1)
        lista_filme = self.__srv.afisare_filme()
        assert (len(lista_filme) == 1)

    def test_sterge_film_dupa_id(self):
        lista_filme = []
        lista_filme.append(self.__srv.adauga_film(1, "Jumanji", "Aventura"))
        film_sters = self.__srv.sterge_film_dupa_id(lista_filme[0].get_id_film())
        assert (film_sters.get_nume_film() == "Jumanji")

    def test_cauta_film_dupa_id(self):
        lista_filme = []
        lista_filme.append(self.__srv.adauga_film(1, "Jumanji", "Aventura"))
        lista_filme.append(self.__srv.adauga_film(2, "Fast and Furious", "Actiune"))
        film_cautat = self.__srv.cauta_film_dupa_id(2)
        assert (film_cautat.get_nume_film() == "Fast and Furious")
        assert (film_cautat.get_gen_film() == "Actiune")
        self.assertRaises(RepoError, self.__srv.cauta_film_dupa_id, 4)


