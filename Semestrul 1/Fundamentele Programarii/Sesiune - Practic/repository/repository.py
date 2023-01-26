from domain.tractor import Tractor

class Repository:

    def __init__(self, filename):
        self.__filename = filename

    def load_from_file(self):
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
        with open(self.__filename, 'w') as f:
            for el in tractoare:
                string = str(el.get_id()) + ';' + str(el.get_denumire()) + ';' + str(el.get_pret()) + ';' + str(el.get_model()) + ';' + str(el.get_data()) + '\n'
                f.write(string)
        f.close()

    def add(self, tractor):
        tractoare = self.load_from_file()
        tractoare.append(tractor)
        self.save_to_file(tractoare)

    def delete(self, id):
        tractoare = []
        for el in self.load_from_file():
            if el.get_id() != id:
                tractoare.append(el)
        self.save_to_file(tractoare)


    def get_all(self):
        return self.load_from_file()


