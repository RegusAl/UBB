from domeniu.atelier import Atelier

class RepoAtelier:

    def __init__(self, filename):
        self.__filename = filename
        self.__lista_ateliere = []

    def _load_from_file(self):
        f = open(self.__filename, 'r', encoding="utf-8")
        lines  = f.readlines()
        for line in lines:
            nume, locatie, produs, numar_spiridusi = [token.strip() for token in line.split(",")]
            atelier = Atelier(nume, locatie, produs, int(numar_spiridusi))
            self.__lista_ateliere.append(atelier)
        f.close()

    def get_all(self):
        self._load_from_file()
        return self.__lista_ateliere