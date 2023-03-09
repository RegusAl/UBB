class PerecheElementFrecventa:
    def __init__(self,e,f):
        self.__e = e
        self.__f = f
    def setElement(self, e):
        self.__e = e
    def setFrecventa(self, f):
        self.__f = f
    def getElement(self):
        return self.__e
    def getFrecventa(self):
        return self.__f
    def __eq__(self, other):
        return (self.__e == other.__e)

class ColectieElementFrecventa:

    def __init__(self):
        self.__perechi = []

    def adauga(self, e):
    #Distingem doua cazuri: elementul apare sau nu deja in colectie
        # Daca elementul apare deja in colectie, ii incrementam frecventa
        # Daca elementul nu apare deja in colectie, il adaugam, cu frecvent 1 
        gasit = False
        for p in self.__perechi:
            if p.getElement()== e:
                p.setFrecventa(p.getFrecventa()+1)
                gasit = True
        if not(gasit):
            p = PerecheElementFrecventa(e,1)
            self.__perechi.append(p)

    def cauta(self, e):
         for p in self.__perechi:
            if p.getElement() == e: 
                return True
         return False

    def sterge(self, e):
    #Distingem trei cazuri: elementul nu arape in colectie, elementul apare in colectie cu o singura data sau elementul apare in colectie de mai multe ori
        # Daca elementul nu apare in colectie, colectia ramane nemodificata
        # Daca elementul apare in colectie o singura data, perechea care il contine va fi stearsa
        # Daca elementul apare in colectie de mai multe ori, frecventa lui va fi decrementata
        for p in self.__perechi:
            if p.getElement() == e:
                if p.getFrecventa() > 1:
                    p.setFrecventa(p.getFrecventa()-1)
                else:
                    self.__perechi.remove(p)
                return True
        return False

    def dim(self):
        d = 0
        for p in self.__perechi:
            d = d + p.getFrecventa()
        return d

    def iterator(self):
        return IteratorColectieFrecventa(self)
		
    def nrAparitii(self, e):
        for p in self.__perechi:
            if p.getElement() == e:
                return p.getFrecventa()
        return 0


class IteratorColectieFrecventa:
    def __init__(self, c):
        self.__col = c
        self.__curent = 0
        self.__f = 1

    def valid(self):
        return self.__curent < len(self.__col._ColectieElementFrecventa__perechi)

    def element(self):
        return self.__col._ColectieElementFrecventa__perechi[self.__curent].getElement()

    def urmator(self):
    #Distingem doua cazuri: frecventa curenta a elementului curent este (1) strict mai mica decat sau (2) egala cu frecventa elementului curent in colectia iterata
        # Daca frecventa curenta a elementului curent este strict mai mica decat frecventa elementului curent in colectia iterata, incrementam frecventa curenta
        # Daca frecventa curenta a elementului curent este egala cu frecventa elementului curent in colectia iterata, trecem la elementul urmator, incrementand indexul curent si reinitializand frecventa curenta cu 1 
        if self.__f < self.__col._ColectieElementFrecventa__perechi[self.__curent].getFrecventa():
           self.__f = self.__f+1
        else:
           self.__curent = self.__curent+1
           self.__f=1
		   
    def prim(self):
        self.__curent = 0
        self.__f = 1

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
    c = ColectieElementFrecventa()
    populeazaColectieIntregi(c)
    print("Numarul de aparitii ale elementului 2: ", c.nrAparitii(2))
    tipareste(c)

main()
