from domain.produs import Produs

class Repository:

    def __init__(self,  filename):
        self.__filename = filename

    def load_from_file(self):
        produse = []
        with open(self.__filename, 'r') as f:
            lines = f.readlines()
            for line in lines:
                line = line.strip()
                id_bicicleta, tip, pret = line.split(", ")
                produs = Produs(int(id_bicicleta), tip, float(pret))
                produse.append(produs)
        f.close()
        return produse

    def save_to_file(self, produse):
        with open(self.__filename, 'w') as f:
            for el in produse:
                string = str(el.get_id_bicicleta()) + ', ' + str(el.get_tip()) + ', ' + str(el.get_pret()) + '\n'
                f.write(string)
        f.close()

    def get_all(self):
        return self.load_from_file()

    def delete(self, id_bicicleta):
        produse = []
        for el in self.load_from_file():
            if el.get_id_bicicleta() != id_bicicleta:
                produse.append(el)
        self.save_to_file(produse)
