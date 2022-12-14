from domeniu.prognoza import PrognozaMeteo


class Repo:

    def __init__(self, filename):
        self.__filename = filename

    def _load_from_file(self):
        '''
        Ia toate prognozele din fisier
        :return: lista de obiecte de tip PrognozaMeteo
        '''
        try:
            f = open(self.__filename, 'r')
        except IOError:
            return
        lines = f.readlines()
        prognoze = []
        for line in lines:
            id, data, oras, prognoza, min, max = [token.strip() for token in line.split(',')]
            forecast = PrognozaMeteo(int(id), data, oras, prognoza, int(min), int(max))
            prognoze.append(forecast)
        f.close()
        return prognoze

    def get_all(self):
        '''
        
        :return:
        '''
        return self._load_from_file()

