import random

from domeniu.piesa_de_teatru import Piesa
from validare.validator_piese import RepoError, ValidError


class Service_Piese:

    def __init__(self, repo, validator):
        self.__repo = repo
        self.__validator = validator

    def get_all(self):
        '''
        Functia ce returneaza lista de piese
        :return: lista de piese
        '''
        return self.__repo.get_all()

    def adauga_piesa(self, titlu, regizor, gen, durata):
        '''
        Functia ce adauga o piesa la lista de piese in fisier
        :param titlu: titlul piesei (string)
        :param regizor: regizorul piesei (string)
        :param gen: genul piesei (string)
        :param durata: durata piesei (int)
        :return: -
        '''
        piesa = Piesa(titlu, regizor, gen, durata)
        self.__validator.validator_piesa(piesa)
        lista_piese = self.get_all()
        lista_piese.append(piesa)
        self.__repo._save_to_file(lista_piese)

    def modifica_piesa(self, titlu, regizor, gen, durata):
        '''
        Functia ce modifica genul si durata unei piese date
        :param titlu: titlul piesei (string)
        :param regizor: regizorul piesei (string)
        :param gen: genul piesei (string)
        :param durata: durata piesei (int)
        :return: -
        '''
        ok = False
        lista_piese = []
        self.__validator.validator_piesa(Piesa(titlu, regizor, gen, durata))
        for el in self.get_all():
            if el.get_titlu() == titlu and el.get_regizor() == regizor:
                el.set_gen(gen)
                el.set_durata(durata)
                ok = True
            lista_piese.append(el)
        if ok == False:
            raise RepoError("Piesa aceasta de teatru nu exista")
        self.__repo._save_to_file(lista_piese)

    def random(self, numar_piese):
        '''
        Functia ce scrie piese random in fisier
        :param numar_piese: numarul de piese random pe care le vrea utilizatorul
        :return: -
        '''
        if numar_piese < 0:
            raise ValidError("Numarul de piese este invalid!")
        lista_piese = self.get_all()
        genuri = ("Comedie", "Drama", "Satira", "Altele")
        vocale = ['A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u']
        consoane = ['B', 'C', 'K', 'D', 'F', 'G', 'H', 'J', 'L', 'M', 'N', 'P', 'R', 'S', 'T', 'V', 'Z', 'b', 'c', 'k', 'd', 'f', 'g', 'h', 'j', 'l', 'm', 'n', 'p', 'r', 's', 't', 'v', 'z']
        for i in range(numar_piese):
            titlu_random = ""
            regizor_random = ""
            random_lungime = random.randint(8, 12)
            random_spatiu = random.randint(0, random_lungime)
            for j in (0, random_lungime):

                random_vocala = random.randint(0, 9)
                random_consoana = random.randint(0, 33)
                titlu_random += vocale[random_vocala]
                titlu_random += consoane[random_consoana]

                random_vocala = random.randint(0, 9)
                random_consoana = random.randint(0, 33)
                regizor_random += vocale[random_vocala]
                regizor_random += consoane[random_consoana]

                if j == random_spatiu:
                    titlu_random += ' '
                    regizor_random += ' '

            gen_random = random.choice(genuri)
            durata_random = random.randint(1, 1000000)
            piesa = Piesa(titlu_random, regizor_random, gen_random, durata_random)
            lista_piese.append(piesa)
        self.__repo._save_to_file(lista_piese)

    def export(self, filename):
        '''
        Functia ce sorteaza lista de piese in funtie de titlu si regizor si exporteaza intr-un fisier cu numele dat de utilizator
        :param filename: numele de fisier in care utilizatorul vrea sa exporteze piesele sortate
        :return: -
        '''
        lista_piese = self.get_all()
        lista_piese.sort(key= lambda x: (x.get_titlu(), x.get_regizor()))
        self.__repo._export(filename, lista_piese)