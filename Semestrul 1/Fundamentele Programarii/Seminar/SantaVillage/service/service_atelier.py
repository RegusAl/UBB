from repository.repo_atelier import RepoAtelier
from validare.exceptii import ExceptionPutiniSpiridusi, ExceptionProdusNegasit, ExceptionNumeInvalid


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

    def organizare_atelier(self, nume, numar_zile):
        numar_spiriduri = 0
        locatie = ""
        ok = False
        for el in self.get_all():
            if el.get_nume() == nume:
                numar_spiriduri = el.get_numar_spiridusi()
                locatie = el.get_locatie()
                ok = True
        if ok == False:
            raise ExceptionNumeInvalid(nume)
        numar_min = numar_spiriduri * numar_zile * 10
        numar_max = numar_spiriduri * numar_zile * 15
        return [nume, numar_spiriduri, locatie, numar_min, numar_max]