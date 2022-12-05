import unittest

from erori.repo_error import RepoError
from infrastructura.repo_clienti import RepoClienti
from infrastructura.repo_inchiriere import RepoInchiriere
from services.service_clienti import ServiceClienti
from validare.validator_clienti import ValidatorClienti

class TestCaseClientiService(unittest.TestCase):

    def setUp(self) -> None:
        repo_clienti = RepoClienti()
        repo_inchiriere = RepoInchiriere()
        validator = ValidatorClienti()
        self.__srv = ServiceClienti(validator, repo_clienti, repo_inchiriere)

    def test_adaugare_client(self):
        lista_clienti = []
        client = self.__srv.adauga_client(1, "Mihai", 5032123456789)
        lista_clienti.append(client)
        # assert (client.get_nume_client() == "Mihai")
        # assert (client.get_cnp_client() == 5032123456789)
        self.assertTrue (len(lista_clienti) == 1)

    def test_afisare_clienti(self):
        lista_clienti = []
        lista_clienti.append(self.__srv.adauga_client(1, "Mihai", 5032123456789))
        lista_clienti = self.__srv.afisare_clienti()
        self.assertTrue (len(lista_clienti) == 1)

    def test_sterge_client_dupa_id(self):
        lista_clienti = []
        lista_clienti.append(self.__srv.adauga_client(1, "Mihai", 5032123456789))
        lista_clienti.append(self.__srv.adauga_client(2, "George", 5034567456789))
        client_sters = self.__srv.sterge_client_dupa_id(2)
        self.assertTrue (client_sters.get_nume_client() == "George")

    def test_cauta_client_dupa_id(self):
        lista_clienti = []
        lista_clienti.append(self.__srv.adauga_client(1, "Mihai", 5032123456789))
        lista_clienti.append(self.__srv.adauga_client(2, "George", 5034567456789))
        self.assertRaises(RepoError, self.__srv.cauta_client_dupa_id, 3)