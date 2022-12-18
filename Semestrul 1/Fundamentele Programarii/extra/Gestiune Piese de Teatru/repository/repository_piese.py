from domeniu.piesa_de_teatru import Piesa


class Repository_Piese:

    def __init__(self, filename):
        self.__filename = filename

    def _load_from_file(self):
        '''
        Functia ce preia piesele din fisier
        :return: lista de piese din fisier
        '''
        f = open(self.__filename, 'r')
        lines = f.readlines()
        lista_piese = []
        for line in lines:
            titlu, regizor, gen, durata = [token.strip() for token in line.split(",")]
            piesa = Piesa(titlu, regizor, gen, int(durata))
            lista_piese.append(piesa)
        f.close()
        return lista_piese

    def get_all(self):
        '''
        Functia ce returneaza toate piesele
        :return: lista de piese
        '''
        return self._load_from_file()

    def _save_to_file(self, lista_piese):
        '''
        Functia ce salveaza lista de piese in fisier
        :param lista_piese: lista de piese curente
        :return: -
        '''
        with open(self.__filename, 'w') as f:
            for piesa in lista_piese:
                piesa_string = str(piesa.get_titlu()) + ', ' + str(piesa.get_regizor()) + ', ' + str(piesa.get_gen()) + ', ' + str(piesa.get_durata()) + '\n'
                f.write(piesa_string)

    def _export(self, filename, lista_piese):
        '''
        Functia export ce scrie in fisierul dat de utilizator lista de piese
        :param filename: numele de fisier
        :param lista_piese: lista de piese
        :return:
        '''
        with open(filename, 'w') as f:
            for piesa in lista_piese:
                piesa_string = str(piesa.get_titlu()) + ', ' + str(piesa.get_regizor()) + ', ' + str(piesa.get_gen()) + ', ' + str(piesa.get_durata()) + '\n'
                f.write(piesa_string)
