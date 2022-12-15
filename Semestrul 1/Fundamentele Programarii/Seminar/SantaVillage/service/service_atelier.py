from repository.repo_atelier import RepoAtelier
from validare.exceptii import ExceptionPutiniSpiridusi, ExceptionProdusNegasit


class ServiceAtelier:

    def __init__(self, repo:RepoAtelier):
        self.__repo = repo

    def get_all(self):
        return self.__repo.get_all()

    def cautare_atelier(self, produs, numar_spiridusi):
        lista_ateliere = []
        nr_produs = 0
        nr_spiridusi = 0
        for el in self.get_all():
            if el.get_produs() == produs and el.get_numar_spiridusi() >= numar_spiridusi:
                lista_ateliere.append(el)
                nr_produs += 1
                nr_spiridusi += 1
            elif el.get_produs() == produs:
                nr_produs += 1
        if nr_produs == 0:
            raise ExceptionProdusNegasit
        elif nr_spiridusi == 0:
            raise ExceptionPutiniSpiridusi(produs)
        return lista_ateliere