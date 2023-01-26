from datetime import datetime

from domain.tractor import Tractor


class Service:

    def __init__(self, repository):
        self.__repository = repository

    def get_all(self):
        return self.__repository.get_all()

    def adaugare_tractor(self, id, denumire, pret, model, data):
        tractor = Tractor(id, denumire, pret, model, data)
        self.__repository.add(tractor)

    def stergere_tractoare(self, cifra):
        nr = 0
        for el in self.__repository.get_all():
            if str(cifra) in str(el.get_pret()):
                self.__repository.delete(el.get_id())
                nr += 1
        return nr

    def filtrare(self, denumire, pret):
        tractoare_filtrate = []
        for el in self.__repository.get_all():
            if pret != -1:
                if denumire in el.get_denumire() and el.get_pret() < pret:
                    tractoare_filtrate.append(el)
            if pret == -1:
                if denumire in el.get_denumire():
                    tractoare_filtrate.append(el)
        for el in tractoare_filtrate:
            day, month, year = el.get_data().split(":")
            if int(year) < datetime.today().year:
                el.set_denumire()
            elif int(year) < datetime.today().year and int(month) < datetime.today().month:
                el.set_denumire()
            elif int(year) < datetime.today().year and int(month) < datetime.today().month and int(day) <= datetime.today().day:
                el.set_denumire()
        return tractoare_filtrate




