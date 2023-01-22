from domain.produs import Produs

class RepoMagazin:

    def __init__(self, filename):
        self.__filename = filename

    # citire din fisier
    def load_from_file(self):
        '''
        Citeste produsele din fisier
        :return: lista de produse
        '''
        produse = []
        with open(self.__filename, 'r') as f:
            lines = f.readlines()
            for line in lines:
                if line != '':
                    line = line.strip()
                    id, denumire, pret = line.split(", ")
                    produs = Produs(int(id), denumire, float(pret))
                    produse.append(produs)
        f.close()
        return produse

    def save_to_file(self, lista):
        '''
        Salveaza lista in fisier
        :param lista: lista de produse ce trebuie salvata in fisier
        :return: -
        '''
        with open(self.__filename, 'w') as f:
            for el in lista:
                line = str(el.get_id()) + ', ' + str(el.get_denumire()) + ', ' + str(el.get_pret()) + '\n'
                f.write(line)
        f.close()
