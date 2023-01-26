from datetime import datetime

from domain.tractor import Tractor


class Service:

    def __init__(self, repository):
        '''
        initializare
        '''
        self.__repository = repository
        self.lista_undo = []

    def get_all(self):
        '''
        Functia returneaza toate tractoarele
        :return: lista de tractoare
        '''
        return self.__repository.get_all()

    def adaugare_tractor(self, id, denumire, pret, model, data):
        '''
        Functia adauga un tractor nou
        :param id: id-ul tractorului
        :param denumire: denumirea tractorului
        :param pret: pretul tractorului
        :param model: modelul tractorului
        :param data: data la care expira revizia tractorului
        :return: -
        '''
        tractor = Tractor(id, denumire, pret, model, data)
        self.undo_list(self.get_all())
        self.__repository.add(tractor)

    def stergere_tractoare(self, cifra):
        '''
        Functia sterge tractoarele ce au in componenta pretului cifra transisa ca parametru
        :param cifra: cifra dupa care se face stergerea
        :return: numarul de tractoare ce au fost sterse
        '''
        nr = 0
        self.undo_list(self.get_all())
        for el in self.__repository.get_all():
            if str(cifra) in str(el.get_pret()):
                self.__repository.delete(el.get_id())
                nr += 1
        return nr

    def filtrare(self, denumire, pret):
        '''
        Functia filtreaza tractoarele dupa denumire si pret
        :param denumire: denumirea dupa care se filtreaza
        :param pret: pretul dupa care se filtreaza
        :return: lista de tractoare filtrate
        '''
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
            elif int(year) == datetime.today().year and int(month) < datetime.today().month:
                el.set_denumire()
            elif int(year) == datetime.today().year and int(month) == datetime.today().month and int(day) <= datetime.today().day:
                el.set_denumire()


        return tractoare_filtrate

    def undo_list(self, lista):
        '''
        Functia ce pune in fisierul de undo lista precedenta
        :param lista: lista de dinainte de operatie
        :return: -
        '''
        self.lista_undo.append(lista)

    def undo(self):
        '''
        Functia ce face undo la ultima operatie efectuata
        :return: -
        '''
        if len(self.lista_undo) >= 1:
            self.__repository.save_to_file(self.lista_undo[-1])
            self.lista_undo.pop()
        else:
            print("Nu se poate face UNDO!")




