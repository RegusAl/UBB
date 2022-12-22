from domeniu.pantof import Pantof

class RepoPantofi:

    def __init__(self, filename):
        self.__filename = filename

    def _load_from_file(self):
        '''
        Functia ce ia entitatile de tip pantof si le pune intr-o lista
        :return: lista de obiecte de tip Pantof
        '''
        f = open(self.__filename, 'r')
        lines = f.readlines()
        pantofi = []
        for line in lines:
            id, denumire, marime, numar_perechi, pret, personalizare = [token.strip() for token in line.split(",")]
            pantof = Pantof(int(id), denumire, int(marime), int(numar_perechi), int(pret), personalizare)
            pantofi.append(pantof)
        f.close()
        return pantofi

    def get_all(self):
        '''
        Functia ce ia toate entitatile din fisier
        :return: lista de pantofi
        '''
        return self._load_from_file()

    def _save_to_file(self, pantofi):
        '''
        Functia ce salveaza in fisier o noua lista de entitati de tipul Pantof
        :param pantofi: lista de obiecte
        :return: -
        '''
        with open(self.__filename, 'w') as f:
            for pantof in pantofi:
                pantof_string = str(pantof.get_id()) + ', ' + str(pantof.get_denumire()) + ', ' + str(pantof.get_marime()) + ', ' + str(pantof.get_numar_perechi()) + ', ' + str(pantof.get_pret()) + ', ' + str(pantof.get_personalizare()) + '\n'
                f.write(pantof_string)