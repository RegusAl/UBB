class Colectie:
    def __init__(self):
        self.__elemente = []
    def adauga(self, e):
        self.__elemente.append(e)
    def cauta(self, e):
        return e in self.__elemente
    def sterge(self, e):
        return self.__elemente.remove(e)
    def dim(self):
        return len(self.__elemente)
    def iterator(self):
        return Iterator(self)
    def nrAparitii(self, e):
        n = 0
        for elem in self.__elemente:
            if elem == e:
                n = n + 1
        return n

class Iterator:
    def __init__(self,c):
        self.__c = c
        self.__curent = 0
    def valid(self):
        return self.__curent < self.__c.dim()
    def element(self):
        return self.__c._Colectie__elemente[self.__curent]
    def urmator(self):
        self.__curent = self.__curent+1
    def prim(self):
        self.__curent = 0
        
def populeazaColectieIntregi(c):
    c.adauga(1)
    c.adauga(2)
    c.adauga(3)
    c.adauga(2)
    c.sterge(2)
    c.adauga(2)
    
def tipareste(c):
    it = c.iterator()
    while it.valid():
        print(it.element())
        it.urmator()
    print("Finalizare tiparire. Sa tiparim din nou continutul colectiei.")
    it.prim()
    while it.valid():
        print(it.element())
        it.urmator()
        
def main():
    c = Colectie()
    populeazaColectieIntregi(c)
    print("Numarul de aparitii ale elementului 2: ", c.nrAparitii(2))
    tipareste(c)

main()
