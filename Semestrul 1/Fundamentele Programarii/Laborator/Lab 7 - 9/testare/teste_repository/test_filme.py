import unittest

from domeniu.filme import Film
from erori.repo_error import RepoError
from infrastructura.repo_filme import RepoFilme

class TestCaseRepoFilme(unittest.TestCase):

    def setUp(self) -> None:
        self.__repo = RepoFilme()

    def test_adauga_film(self):
        film = Film(1, "Exemplu", "Aventura")
        self.__repo.adauga_film(film)
        self.assertTrue (self.__repo.__sizeof__(), 1)
        film = Film(1, "Exemplu2", "Aventura")
        self.assertRaises(RepoError, self.__repo.adauga_film, film)

    def test_stergere_film(self):
        self.__repo.adauga_film(Film(1, "Exemplu", "Aventura"))
        self.__repo.adauga_film(Film(2, "Exemplu2", "Aventura"))
        self.__repo.adauga_film(Film(3, "Exemplu3", "Aventura"))
        self.assertRaises(RepoError, self.__repo.stergere_film, 4)