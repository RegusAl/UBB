from domain.eveniment import Eveniment

class ServiceEvenimente:

    def __init__(self, repository, validare):
        self.__repository = repository
        self.__validare = validare

    def evenimente_zi_curenta(self):
        '''
        Functia returneaza evenimentele din ziua curenta, sortate dupa ora
        :return: evenimentele din ziua curenta (lista de obiecte)
        '''
        evenimente_zi_curenta =  self.__repository.get_all_today()
        evenimente_zi_curenta.sort(key = lambda x: x.get_ora(), reverse = False)
        return evenimente_zi_curenta

    def adaugare_eveniment(self, data, ora, descriere):
        '''
        Functia adauga un nou eveniment. Functia valideaza datele transmise prin paramentrii si dupa salveaza  in fisier evenimentele
        :param data: data evenimentului (string)
        :param ora: ora evenimentului (string)
        :param descriere: descrierea evenimentului (string)
        :return: -
        '''
        self.__validare.validare(data, ora)
        eveniment = Eveniment(data, ora, descriere)
        evenimente = self.__repository.load_from_file()
        evenimente.append(eveniment)
        self.__repository.save_to_file(evenimente)

    def stabilire_data(self, data):
        '''
        Functia returneaza evenimentele din aceeasi data transmisa ca paramentru
        :param data: data pentru care se afiseaza evenimentele (string)
        :return: evenimentele din data transmisa ca parametru
        '''
        evenimente = []
        for el in self.__repository.load_from_file():
            if el.get_data() == data:
                evenimente.append(el)
        return evenimente

    def export(self, nume_fisier, sir):
        '''
        Functia exporta evenimentele ce au in descriere caracterele din sirul transmis ca parametru.
        Evenimentele sunt sortate in functie de data si de ora
        :param nume_fisier: numele fisierului in care se vor exporta evenimentele (string)
        :param sir: sirul de caractere ce trebuie sa apare in descrierea evenimentelor exportate
        :return: -
        '''
        evenimente = []
        for el in self.__repository.load_from_file():
            if sir in el.get_descriere():
                evenimente.append(el)
        evenimente.sort(key = lambda x:(x.get_data(), x.get_ora()))
        self.__repository.export(nume_fisier, evenimente)
        return evenimente
