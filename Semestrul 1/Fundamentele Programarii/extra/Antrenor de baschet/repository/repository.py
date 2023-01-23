from domain.jucator import Jucator


class Repository:

    def __init__(self, filename):
        self.__filename = filename

    def load_from_file(self):
        '''
        Functia ce extrage jucatorii din fisier
        :return: lista de obiecte de tipul jucator
        '''
        echipa = []
        with open(self.__filename, 'r') as f:
            lines = f.readlines()
            for line in lines:
                if line != '':
                    line = line.strip()
                    nume, prenume, inaltime, post = line.split(" ")
                    jucator = Jucator(nume, prenume, int(inaltime), post)
                    echipa.append(jucator)
        f.close()
        return echipa

    def save_to_file(self, echipa):
        '''
        Functia ce salveaza in fisier lista de obiecte 'echipa', transmisa prin parametru
        :param echipa: lista de obiecte de tipul 'jucator'
        :return: -
        '''
        with open(self.__filename, 'w') as f:
            for el in echipa:
                string = str(el.get_nume()) + ' ' + str(el.get_prenume()) + ' ' + str(el.get_inaltime()) + ' ' + str(el.get_post()) + '\n'
                f.write(string)
        f.close()
