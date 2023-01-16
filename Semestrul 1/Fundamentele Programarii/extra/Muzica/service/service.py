import random

from domeniu.melodie import Melodie


class Service:

    def __init__(self, repo, validator):
        self.__repo = repo
        self.__validator = validator

    def get_all(self):
        '''
        Functia ce returneaza toate melodiile
        :return: lista de melodii
        '''
        return self.__repo.get_all()

    def modificare_melodie(self, titlu, artist, gen, durata):
        '''
        Functia ce modifica melodia in functie de parametrii dati de utilizator
        :param titlu: titlul melodiei ce trebuie modificata
        :param artist: artistul melodiei ce trebuie modificata
        :param gen: genul melodiei ce se modifica
        :param durata: durata melodiei ce se modifica
        :return: -
        '''
        m = Melodie(titlu, artist, gen, durata)
        self.__validator.validator_melodie(m)
        lista_melodii = []
        for el in self.get_all():
            if el.get_titlu() == titlu and el.get_artist() == artist:
                melodie = Melodie(titlu, artist, gen, durata)
                lista_melodii.append(melodie)
            else:
                lista_melodii.append(el)
        self.__repo.save_to_file(lista_melodii)

    def melodii_random(self, numar, lista_titluri, lista_artisti):
        '''
        Functia ce adauga un numar transmis ca parametru de melodii random
        :param numar: numarul de melodii ce se adauga
        :param lista_titluri: lista de titluri
        :param lista_artisti: lista de artisti
        :return: -
        '''
        lista_melodii = self.get_all()
        lista_genuri = ["Rock", "Pop", "Jazz", "Altele"]
        ok = 1
        for i in range (0, numar):
            titlu = random.choice(lista_titluri)
            artist = random.choice(lista_artisti)
            gen = random.choice(lista_genuri)
            durata = random.randint(60, 200)
            melodie = Melodie(titlu, artist, gen, durata)
            for el in lista_melodii:
                if el.get_titlu() == titlu and el.get_artist() == artist:
                    ok = 0
            if ok == 1:
                lista_melodii.append(melodie)
        self.__repo.save_to_file(lista_melodii)

    def export(self, nume_fisier):
        '''
        Functia ce face export la lista de melodii sortate dupa titlu si artist in fisierul transmis ca parametru
        :param nume_fisier: numele fisierului unde se salveaza lista cu melodii
        :return: -
        '''
        lista_melodii = self.get_all()
        lista_melodii_sortate = sorted(lista_melodii, key = lambda x: (x.get_titlu(), x.get_artist()))
        with open(nume_fisier, 'w') as f:
            for el in lista_melodii_sortate:
                string = str(el.get_titlu()) + ', ' + str(el.get_artist()) + ', ' + str(el.get_gen()) + ', ' + str(
                    el.get_durata()) + '\n'
                f.write(string)
        return lista_melodii_sortate
