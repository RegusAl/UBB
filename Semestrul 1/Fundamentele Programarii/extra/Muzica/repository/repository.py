from domeniu.melodie import Melodie


class Repository:

    def __init__(self, filename):
        self.__filename = filename

    def load_from_file(self):
        '''
        Functia ce preia toate melodiile din fisier
        :return: lista de melodii
        '''
        f = open(self.__filename, 'r')
        lines = f.readlines()
        melodii = []
        for line in lines:
            titlu, artist, gen, durata = [token.strip() for token in line.split(',')]
            melodie = Melodie(titlu, artist, gen, int(durata))
            melodii.append(melodie)
        f.close()
        return melodii

    def get_all(self):
        '''
        Functia ce returneaza toate melodiile
        :return: lista de melodii
        '''
        return self.load_from_file()

    def save_to_file(self, lista):
        '''
        Functia ce salveaza lista de melodii modificata in fisier
        :param lista: lista de melodii noua
        :return: -
        '''
        with open(self.__filename, 'w') as f:
            for el in lista:
                string = str(el.get_titlu()) + ', ' + str(el.get_artist()) + ', ' + str(el.get_gen()) + ', ' + str(el.get_durata()) + '\n'
                f.write(string)

