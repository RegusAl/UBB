import unittest

from repository.repo import Repo
from service.service import Service


class MyTestCase(unittest.TestCase):

    def setUp(self) -> None:
        self.__repo = Repo("prognoza-test.txt")
        self.__service = Service(self.__repo)

    def test_get_all(self):
        '''
        Testeaza functia get_all()
        :return:
        '''
        lista = self.__repo.get_all()
        assert (len(lista) == 10)

    def test_load_from_file(self):
        '''
        Testeaza luarea obiectelor din fisier
        :return:
        '''
        lista_din_fisier = self.__repo._load_from_file()
        assert (len(lista_din_fisier) == 10)
        assert (lista_din_fisier[9].get_id() == 71)

    def test_locatii_string(self):
        '''
        testeaza functia locatii_string()
        :return:
        '''
        lista = self.__service.locatii_string("ej")
        assert (lista[0].get_id() == 55)
        lista = self.__service.locatii_string("Buc")
        assert (len(lista) == 4)



if __name__ == '__main__':
    unittest.main()
