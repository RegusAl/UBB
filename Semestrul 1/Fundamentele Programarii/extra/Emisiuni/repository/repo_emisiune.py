from domeniu.emisiune import Emisiune


class RepoEmisiune:

    def __init__(self, filename):
        self.__filename = filename

    def load_from_file(self):
        '''
        Functia ce ia emisiunile din fisier
        :return: lista de emisiuni
        '''
        lista_emisiune = []
        f = open(self.__filename, 'r')
        lines = f.readlines()
        for line in lines:
            nume, tip, durata, descriere = [token.strip() for token in line.split(',')]
            emisiune = Emisiune(nume, tip, int(durata), descriere)
            lista_emisiune.append(emisiune)
        f.close()
        return lista_emisiune

    def save_to_file(self, lista):
        '''
        Fuinctia ce salveaza lista de emisiuni in fisier
        :param lista: lista de emisiuni
        :return: -
        '''
        with open(self.__filename, 'w') as f:
            for emisiune in lista:
                f.write(f'{emisiune.get_nume()}, {emisiune.get_tip()}, {emisiune.get_durata()}, {emisiune.get_descriere()}\n')
        f.close()