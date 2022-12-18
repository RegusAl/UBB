import unittest

from domeniu.piesa_de_teatru import Piesa
from repository.repository_piese import Repository_Piese


class TestRepositoryCase(unittest.TestCase):

    def setUp(self) -> None:
        self.__repo = Repository_Piese("piese-test.txt")

    def test_load_from_file(self):
        lista_piese = self.__repo._load_from_file()
        self.assertEqual(len(lista_piese), 8)
        self.assertEqual(lista_piese[0].get_titlu(), "O scrisoare Pierduta")
        self.assertEqual(lista_piese[0].get_gen(), "Comedie")
        self.assertEqual(lista_piese[2].get_regizor(), "Frank")

    def test_get_all(self):
        lista_piese = self.__repo.get_all()
        self.assertEqual(len(lista_piese), 8)

    def test_save_to_file(self):
        lista_piese = self.__repo.get_all()
        lista_noua_piese = lista_piese.copy()
        lista_noua_piese.append(Piesa("EX1", "Regizor", "Comedie", 123))
        self.__repo._save_to_file(lista_noua_piese)
        self.assertEqual(len(self.__repo.get_all()), 9)
        self.__repo._save_to_file(lista_piese)

    def test_export(self):
        lista_piese_export = self.__repo.get_all()
        self.__repo._export("export_repo_test.txt", lista_piese_export)
        f = open("export_repo_test.txt", 'r')
        lines = f.readlines()
        lista_piese = []
        for line in lines:
            titlu, regizor, gen, durata = [token.strip() for token in line.split(",")]
            piesa = Piesa(titlu, regizor, gen, int(durata))
            lista_piese.append(piesa)
        f.close()
        self.assertEqual(len(lista_piese), 8)
        self.assertEqual(lista_piese[0].get_titlu(), "O scrisoare Pierduta")
        self.assertEqual(lista_piese[0].get_gen(), "Comedie")
        self.assertEqual(lista_piese[2].get_regizor(), "Frank")
