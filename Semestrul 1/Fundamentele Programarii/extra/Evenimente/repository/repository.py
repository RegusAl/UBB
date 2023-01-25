from datetime import date

from domain.eveniment import Eveniment


class RepositoryEvenimente:

    def __init__(self, filename):
        self.__filename = filename

    def load_from_file(self):
        '''
        Functia ce ia toate evenimentele din fisier
        :return: lista de evenimente (lista de obiecte de tip "Eveniment")
        '''
        evenimente = []
        with open(self.__filename, 'r') as f:
            lines = f.readlines()
            for line in lines:
                if line != '':
                    line = line.strip()
                    data, ora, descriere = line.split(",")
                    eveniment = Eveniment(data, ora, descriere)
                    evenimente.append(eveniment)
        f.close()
        return evenimente

    def save_to_file(self, evenimente):
        '''
        Functia salveaza lista de evenimente transmisa ca parametru in fisier
        :param evenimente: lista de evenimente (lista de obiecte de  tip "Eveniment")
        :return: -
        '''
        with open(self.__filename, 'w') as f:
            for el in evenimente:
                string = str(el.get_data()) + ',' + str(el.get_ora()) + ',' + str(el.get_descriere()) + '\n'
                f.write(string)
        f.close()

    def get_all_today(self):
        '''
        Functia returneaza toate evenimentele din ziua curenta
        :return: lista de evenimente din ziua curenta
        '''
        evenimente = self.load_from_file()
        evenimente_zi_curenta = []
        zi_curenta = date.today()
        for el in evenimente:
            zi, luna, an = el.get_data().split(".")
            if int(zi) == zi_curenta.day and int(luna) == zi_curenta.month and int(an) == zi_curenta.year:
                evenimente_zi_curenta.append(el)
        return evenimente_zi_curenta

    def export(self, nume_fisier, evenimente):
        '''
        Functia exporta lista de evenimente in fisierul cu numele transmis ca parametru
        :param nume_fisier: numele fisierului in care se exporta evenimentele
        :param evenimente: lista de evenimente (lista de obiecte de tip "Eveniment")
        :return: -
        '''
        with open(nume_fisier, 'w') as f:
            for el in evenimente:
                string = str(el.get_data()) + ', ' + str(el.get_ora()) + ', ' + str(el.get_descriere()) + '\n'
                f.write(string)
        f.close()
