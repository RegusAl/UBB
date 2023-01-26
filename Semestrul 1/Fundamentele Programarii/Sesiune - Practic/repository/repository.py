from domain.tractor import Tractor

class Repository:

    def __init__(self, filename):
        '''
        initializare
        :param filename: numele de fisier
        '''
        self.__filename = filename

    def load_from_file(self):
        '''
        Functia ia din fisier toate tractoarele
        :return: lista de tractoare
        '''
        tractoare = []
        with open(self.__filename, 'r') as f:
            lines = f.readlines()
            for line in lines:
                if line != '':
                    line = line.strip()
                    id, denumire, pret, model, data = line.split(";")
                    tractor = Tractor(int(id), denumire, int(pret), model, data)
                    tractoare.append(tractor)
        f.close()
        return tractoare

    def save_to_file(self, tractoare):
        '''
        Functia salveaza in fisier lista de tractoare
        :param tractoare: lista de tractoare
        :return: -
        '''
        with open(self.__filename, 'w') as f:
            for el in tractoare:
                string = str(el.get_id()) + ';' + str(el.get_denumire()) + ';' + str(el.get_pret()) + ';' + str(el.get_model()) + ';' + str(el.get_data()) + '\n'
                f.write(string)
        f.close()

    def add(self, tractor):
        '''
        Functia adauga in fisier un tractor nou
        :param tractor: tractorul ce trebuie adaugat in fisier
        :return: -
        '''
        tractoare = self.load_from_file()
        tractoare.append(tractor)
        self.save_to_file(tractoare)

    def delete(self, id):
        '''
        Functia sterge tractorul din fisier in functie de id
        :param id: id-ul tractorului ce se sterge
        :return: -
        '''
        tractoare = []
        for el in self.load_from_file():
            if el.get_id() != id:
                tractoare.append(el)
        self.save_to_file(tractoare)


    def get_all(self):
        '''
        Functia returneaza toate tractoarele
        :return: lista de tractoare
        '''
        return self.load_from_file()


