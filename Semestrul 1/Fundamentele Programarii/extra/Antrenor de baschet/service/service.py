import random

from domain.jucator import Jucator

class Service:

    def __init__(self, repository):
        self.__repository = repository

    def adaugare_jucator(self, nume, prenume, inaltime, post):
        '''
        Functia adauga un jucator nou in fisier.
        :param nume: numele jucatorului
        :param prenume: prenumele jucatorului
        :param inaltime: inaltimea jucatorului
        :param post: postul jucatorului
        :return: -
        :raises: ValueError: - daca numele, prenumele este vid
                             - daca inaltimea este vida sau este negativa
                             - daca postul nu este valid
        '''
        errori = []
        if nume == '':
            errori.append("Numele nu poate fi vid!")
        if prenume == '':
            errori.append("Prenumele nu poate fi vid!")
        if inaltime <= 0 or inaltime == '':
            errori.append("Inaltimea trebuie sa fie un numar pozitiv!")
        if post not in ["Fundas", "Pivot", "Extrema"]:
            errori.append("Postul este invalid!")
        if len(errori) > 1:
            raise ValueError(errori)
        echipa = self.__repository.load_from_file()
        jucator = Jucator(nume, prenume, inaltime, post)
        echipa.append(jucator)
        self.__repository.save_to_file(echipa)

    def modifica_inaltime(self, nume, prenume, inaltime):
        '''
        Functia modifica inaltimea unui jucator deja existent
        :param nume: numele jucatorului
        :param prenume: prenumele jucatorului
        :param inaltime: inaltimea noua
        :return: -
        '''
        echipa = self.__repository.load_from_file()
        for el in echipa:
            if el.get_nume() == nume and el.get_prenume() == prenume:
                el.set_inaltime(inaltime)
        self.__repository.save_to_file(echipa)

    def echipa_valida(self):
        '''
        Functia formeaza o echipa valida.
        :return: echipa valida de jucatori (lista de jucatori)
        '''
        echipa = self.__repository.load_from_file()
        echipa.sort(key = lambda x : x.get_inaltime())
        echipa_valida = []
        extrema = 2
        fundas = 2
        pivot = 1
        while extrema + fundas + pivot > 0:
            if echipa[-1].get_post() == "Extrema":
                extrema -= 1
                echipa_valida.append(echipa[-1])
            if echipa[-1].get_post() == "Fundas":
                fundas -= 1
                echipa_valida.append(echipa[-1])
            if echipa[-1].get_post() == "Pivot":
                pivot -= 1
                echipa_valida.append(echipa[-1])
            echipa.pop()
        return echipa_valida

    def import_jucatori(self, nume_fisier):
        '''
        Functia importa jucatori unici din fisierul transmis ca parametru
        :param nume_fisier: numele fisierului din care se importa
        :return: numarul de jucatori unici ce au fost adaugati
        '''
        echipa = self.__repository.load_from_file()
        numar = 0
        posturi = ["Fundas", "Pivot", "Extrema"]
        with open(nume_fisier, 'r') as f:
            lines = f.readlines()
            for line in lines:
                if line != '':
                    line = line.strip()
                    nume, prenume = line.split(" ")
                    post = random.choice(posturi)
                    inaltime = random.randint(170, 210)
                    jucator = Jucator(nume, prenume, inaltime, post)
                    ok = 1
                    for el in echipa:
                        if el.get_nume() == jucator.get_nume() and el.get_prenume() == jucator.get_prenume():
                            ok = 0
                    if ok == 1:
                        echipa.append(jucator)
                        numar += 1
            f.close()
        self.__repository.save_to_file(echipa)
        return numar

