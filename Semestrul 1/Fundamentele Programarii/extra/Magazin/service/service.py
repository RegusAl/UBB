from domain.produs import Produs

class ServiceMagazin:

    def __init__(self, repository):
        self.__repository = repository

    def get_all(self):
        return self.__repository.load_from_file()

    def adaugare_produs(self, id, denumire, pret):
        '''
        Adauga un produs noi in lista de produse
        :param id: id-ul produsului nou
        :param denumire: denumirea produsului
        :param pret: pretul produsului
        :return: -
        '''
        lista = self.__repository.load_from_file()
        lista.append(Produs(id, denumire, pret))
        self.__repository.save_to_file(lista)

    def stergere_produse(self, n):
        '''
        Sterge produsele ce contin cifra n in id
        :param n: cifra
        :return: numarul de produse sterse
        '''
        lista = self.__repository.load_from_file()

        lista_noua = []
        sters = 0
        for el in lista:
            ok = 1
            id = el.get_id()
            while id > 0 and ok:
                if id % 10 == n:
                    ok = 0
                id = id // 10
            if ok == 0:
                sters += 1
            else:
                lista_noua.append(el)
        self.__repository.save_to_file(lista_noua)
        return sters

    def filtrare(self, denumire, numar):
        '''
        Filtreaza in functie de denumire si pret
        :param denumire: denumirea
        :param numar: pretul
        :return: lista de produse filtrate
        '''
        lista_filtrata = []
        if denumire == '' and numar == -1:
            return self.__repository.load_from_file()
        for el in self.__repository.load_from_file():
            if denumire == '' and el.get_pret() < numar:
                lista_filtrata.append(el)
            elif denumire in el.get_denumire() and numar == -1:
                lista_filtrata.append(el)
            elif denumire in el.get_denumire() and el.get_pret() < numar:
                lista_filtrata.append(el)
        return lista_filtrata

    def update_undo(self, crt_undo, cifra):
        '''
        Adauga la lista de undo o lista ce contine toate elementele ce urmeaza a fi sterse
        :param crt_undo: lista ce contine toate produsele sterse
        :param cifra: cifra dupa care se face stergerea
        :return: lista de undo
        '''
        lista = self.__repository.load_from_file()
        lista_produse_sterse = []
        for el in lista:
            if str(cifra) in str(el.get_id()):
                lista_produse_sterse.append(el)
        copy_list = []
        for el in lista_produse_sterse:
            copy_list.append(Produs(el.get_id(), el.get_denumire(), el.get_pret()))
        crt_undo.append(copy_list)
        return crt_undo

    def undo(self, crt_undo):
        '''
        Adauga produsele ce au fost sterse
        :param crt_undo: lista ce aretinut produsele sterse
        :return: lista de undo
        '''
        errors = []
        if len(crt_undo) < 1:
            errors = "Nu se poate face undo!"
        else:
            for el in crt_undo[-1]:
                self.adaugare_produs(el.get_id(), el.get_denumire(), el.get_pret())
        if len(errors) > 0:
            error_string = errors
            raise ValueError(error_string)
        crt_undo.pop(-1)
        return crt_undo
