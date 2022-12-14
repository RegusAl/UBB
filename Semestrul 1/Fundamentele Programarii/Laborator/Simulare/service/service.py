def RepoError(exception):
    pass

class Service:

    def __init__(self, repo):
        self.__repo = repo

    def get_all(self):
        '''
        Ia toate prognozele din repo
        :return: lista de obiecte
        '''
        return self.__repo.get_all()

    def locatii_string(self, string):
        '''
        Ia 'string-ul' dat de utilizator, pe care il cauta in locatiile prognozelor.
        Sorteaza in functie de data
        :param string: (string) - stringul dat de catre utilizator
        :return: returneaza prognozele meteo srtate descrescator dupa data
        '''
        prognoze = self.get_all()
        prognoze_noi = []
        for el in prognoze:
            if string in el.get_locatia():
                prognoze_noi.append(el)
        date = []
        for el in prognoze_noi:
            date.append(el.get_data())
        date.sort(reverse=True)
        if len(date) == 0:
            raise RepoError("Nu exista!")
        prognoze_sortate = []
        for i in range(len(date)):
            for el in prognoze_noi:
                if el.get_data() == date[i]:
                    prognoze_sortate.append(el)
        return prognoze_sortate

    def grupare_locatie(self):
        lista = self.get_all()
        locatii = []
        for loc in lista:
            if {"oras": loc.get_locatia(), "temperatura": ["min", "max"], "vreme": [], "numar": []} not in locatii:
                locatii.append({"oras": loc.get_locatia(), "temperatura": ["min", "max"], "vreme": [], "numar": []})
        numar = [0, 0, 0, 0, 0, 0, 0, 0]
        for loc in locatii:
            for el in lista:
                if el.get_locatia() == loc["oras"]:
                    # temperatura minima
                    if loc["temperatura"][0] == "min":
                        loc["temperatura"][0] = el.get_temp_minima()
                    elif el.get_temp_minima() < loc["temperatura"][0]:
                        loc["temperatura"][0] = el.get_temp_minima()
                    # temperatura maxima
                    if loc["temperatura"][1] == "max":
                        loc["temperatura"][1] = el.get_temp_maxima()
                    elif el.get_temp_maxima() > loc["temperatura"][1]:
                        loc["temperatura"][1] = el.get_temp_maxima()
                    # vreme
                    if el.get_prognoza() not in loc["vreme"]:
                        loc["vreme"].append(el.get_prognoza())
                    # numar prognoze
                    for i in range(len(loc["vreme"])):
                        if el.get_prognoza() == loc["vreme"][i] and len(loc["numar"])<=i:
                            loc["numar"].append(1)
                        elif el.get_prognoza() == loc["vreme"][i]:
                            loc["numar"][i] += 1
        return locatii









