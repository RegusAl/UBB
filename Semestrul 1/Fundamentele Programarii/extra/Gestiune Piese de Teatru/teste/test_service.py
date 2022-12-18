import unittest

from domeniu.piesa_de_teatru import Piesa
from repository.repository_piese import Repository_Piese
from service.service_piese import Service_Piese
from validare.validator_piese import Validator, ValidError, RepoError


class TestServiceCase(unittest.TestCase):

    def setUp(self) -> None:
        self.__repo = Repository_Piese("piese-test.txt")
        validator = Validator()
        self.__service = Service_Piese(self.__repo, validator)

    def test_get_all(self):
        lista_piese = self.__service.get_all()
        self.assertEqual(len(lista_piese), 8)
        self.assertEqual(lista_piese[0].get_titlu(), "O scrisoare Pierduta")
        self.assertEqual(lista_piese[0].get_gen(), "Comedie")
        self.assertEqual(lista_piese[2].get_regizor(), "Frank")

    def test_adauga_piesa(self):
        lista_piese = self.__service.get_all()
        self.__service.adauga_piesa("EX1", "NUJ", "Drama", 12345)
        lista_noua = self.__service.get_all()
        self.assertEqual(len(lista_noua), 9)
        self.__repo._save_to_file(lista_piese)
        self.assertRaises(ValidError, self.__service.adauga_piesa, "nuj", "nuj", "Comedie", -123)
        self.assertRaises(ValidError, self.__service.adauga_piesa, "", "nuj", "Comedie", 123456)
        self.assertRaises(ValidError, self.__service.adauga_piesa, "nuj", "", "Comedie", 123)
        self.assertRaises(ValidError, self.__service.adauga_piesa, "lol", "nuj", "nuj", 123456)

    def test_modifica_piesa(self):
        lista_piese = self.__service.get_all()
        self.__service.modifica_piesa("Ana", "Popescu Gica", "Drama", 890)
        lista_noua = self.__service.get_all()
        self.assertEqual(lista_noua[5].get_gen(), "Drama")
        self.assertEqual(lista_noua[5].get_durata(), 890)
        self.assertRaises(RepoError, self.__service.modifica_piesa, "Nuj", "nuj", "Comedie", 1234)
        self.__repo._save_to_file(lista_piese)

    def test_random(self):
        lista_piese = self.__service.get_all()
        self.__service.random(5)
        lista_noua = self.__service.get_all()
        self.assertEqual(len(lista_noua), 13)
        self.__repo._save_to_file(lista_piese)

    def test_export(self):
        self.__service.export("export_service_test.txt")
        f = open("export_service_test.txt", 'r')
        lines = f.readlines()
        lista_piese = []
        for line in lines:
            titlu, regizor, gen, durata = [token.strip() for token in line.split(",")]
            piesa = Piesa(titlu, regizor, gen, int(durata))
            lista_piese.append(piesa)
        f.close()
        self.assertEqual(len(lista_piese), 8)
        self.assertEqual(lista_piese[0].get_titlu(), "Alt Exemplu")
        self.assertEqual(lista_piese[7].get_titlu(), "Titanic")


