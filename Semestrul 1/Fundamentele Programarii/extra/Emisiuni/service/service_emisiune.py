import random
from domeniu.emisiune import Emisiune
from erori.erori import RepoError, BlocatError


class ServiceEmisiune:

    def __init__(self, repo):
        self.__repo = repo
        self.__blocat = []

    def get_all(self):
        '''
        Functia ce returneaza toate emisiunile
        :return: lista de emisiuni
        '''
        return self.__repo.load_from_file()

    def stergere_emisiune(self, nume, tip):
        '''
        Functia ce sterge o emisiune in functie de nume si tip stransmis prin parametru
        :param nume: numele emisiunii ce trebuie stearsa
        :param tip: tipul emisiunii ce trebuie sters
        :return: -
        :raise: RepoError: daca emisiunea nu exista
        '''
        lista_emisiuni = self.get_all()
        lista_noua = []
        ok = False
        for el in lista_emisiuni:
            if el.get_nume() == nume and el.get_tip() == tip and tip in self.__blocat:
                lista_noua.append(el)
                raise BlocatError("Emisiune blocata!")
            elif el.get_nume() == nume and el.get_tip() == tip:
                ok = True
            else:
                lista_noua.append(el)
        if ok == False:
            raise RepoError("Emisiunea nu exista!")
        self.__repo.save_to_file(lista_noua)

    def modificare_emisiune(self, nume, tip, durata, descriere):
        '''
            Functia ce modifica o emisiune in functie de nume si tip stransmis prin parametru

            :param nume: numele emisiunii ce trebuie modificata
            :param tip: tipul emisiunii ce trebuie modificata
            :param durata: durata emisiunii se schimba cu aceasta durata data de utilizator
            :param descriere: descrierea emisiunii se schimba cu aceasta descriere data de utilizator
            :return: -
            :raise: RepoError: daca emisiunea nu exista
        '''
        lista_emisiuni = self.get_all()
        lista_noua = []
        ok = False
        for el in lista_emisiuni:
            if el.get_nume() == nume and el.get_tip() == tip and tip in self.__blocat:
                lista_noua.append(el)
                raise BlocatError("Emisiune blocata!")
            elif el.get_nume() == nume and el.get_tip() == tip:
                ok = True
                emisiune = Emisiune(nume, tip, durata, descriere)
                lista_noua.append(emisiune)
            else:
                lista_noua.append(el)
        if ok == False:
            raise RepoError("Emisiunea nu exista!")
        self.__repo.save_to_file(lista_noua)

    def program_random(self, ora_inceput, ora_sfarsit):
        '''
        Functia ce face un program TV random
        :param ora_inceput: ora de inceput a programului
        :param ora_sfarsit: ora de sfarsit a programului
        :return: program (lista de emisiuni)
        '''
        program = []
        emisiuni = self.get_all()
        numar_emisiuni = len(emisiuni)
        timp = 0
        while timp <= ora_sfarsit-ora_inceput:
            numar = random.randint(0, numar_emisiuni-1)
            if emisiuni[numar].get_tip() not in self.__blocat and emisiuni[numar] not in program:
                program.append(emisiuni[numar])
                timp += emisiuni[numar].get_durata()
            elif emisiuni[numar].get_tip() not in self.__blocat and emisiuni[numar] in program:
                emisiune_extra = Emisiune(emisiuni[numar].get_nume(), emisiuni[numar].get_tip(), emisiuni[numar].get_durata(), emisiuni[numar].get_descriere() + '****')
                timp += emisiuni[numar].get_durata()
                program.append(emisiune_extra)
        return program

    def blocare_tip(self, tip):
        self.__blocat.append(tip)

    def tipuri_blocate(self):
        return self.__blocat

    def deblocheaza_tip(self, tip):
        self.__blocat.remove(tip)

    def deblocheaza_tot(self):
        self.__blocat.clear()
