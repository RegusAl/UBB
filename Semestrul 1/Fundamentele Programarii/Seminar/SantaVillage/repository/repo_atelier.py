from domeniu.atelier import Atelier

class RepoAtelier:

    def __init__(self, filename):
        self.__filename = filename

    def _load_from_file(self):
        f = open(self.__filename, 'r', encoding="utf-8")
        lines  = f.readlines()
        lista_ateliere = []
        for line in lines:
            nume, locatie, produs, numar_spiridusi = [token.strip() for token in line.split(",")]
            atelier = Atelier(nume, locatie, produs, int(numar_spiridusi))
            lista_ateliere.append(atelier)
        f.close()
        return lista_ateliere

    def get_all(self):
        return self._load_from_file()
