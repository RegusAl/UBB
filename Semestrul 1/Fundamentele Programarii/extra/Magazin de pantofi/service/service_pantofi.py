from validator.validator import RepoError


class ServicePantofi:

    def __init__(self, repo, validator):
        self.__repo = repo
        self.__validator = validator

    def get_all(self):
        '''
        Functia ce returneaza lista de pantofi
        :return: lista de obiecte de tipul Pantof
        '''
        return self.__repo.get_all()

    def afisare_dupa_denumire(self, denumire):
        '''
        Functia returneaza lista de pantofi ce au ca denumire stringul dat de utilizator si care se pot personaliza
        :param denumire: denumirea pantofilor pe care utilizatorul ii cauta
        :return: lista de obiecte de tip pantof
        '''
        lista_pantofi = []
        ok = False
        for el in self.get_all():
            if el.get_denumire() == denumire and el.get_personalizare() == 'True':
                lista_pantofi.append(el)
                ok = True
        if ok == False:
            raise RepoError("Nu exista pantofi cu aceasta denumire!")
        lista_pantofi.sort(key = lambda x: x.get_marime())
        return lista_pantofi

    def comandare(self, id):
        '''
        Functia cauta in lista de pantofi id-ul dat de utilizator si "comanda" o pereche
        In cazul in care id-ul nu exista se afiseaza o eroare
        In cazul in care numarul de perechi este 0, atunci se returneaza o lista de pantofi de marimea pantofilor cautati de utilizator
        :param id: id-ul dat de utilizator pentru a cauta o pereche de pantofi
        :return: lista de pantofi
        '''
        lista_pantofi_comandati = []
        lista_de_actualizat = []
        ok = False
        marime = 0
        for el in self.get_all():
            if el.get_id() == id and el.get_numar_perechi() > 0:
                nr = el.get_numar_perechi() - 1
                el.set_numar_perechi(nr)
                lista_pantofi_comandati.append(el)
            elif el.get_id() == id and el.get_numar_perechi() == 0:
                marime = el.get_marime()
            lista_de_actualizat.append(el)
        self.__repo._save_to_file(lista_de_actualizat)
        if len(lista_pantofi_comandati) == 0:
            for el in self.get_all():
                if el.get_marime() == marime and el.get_numar_perechi() > 0:
                    lista_pantofi_comandati.append(el)
                    ok = True
        if ok == True:
            print("Ne pare rau. Nu mai avem acea pereche de pantofi")
        if len(lista_pantofi_comandati) == 0:
            raise RepoError(f"Perechea de pantofi cu id-ul {id} nu exista!")
        return lista_pantofi_comandati