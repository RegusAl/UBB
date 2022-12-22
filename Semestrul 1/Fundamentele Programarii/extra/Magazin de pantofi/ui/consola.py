from validator.validator import RepoError

class Consola:

    def __init__(self, service):
        self.__service = service

    def _ui_afisare(self):
        try:
            denumire = input("Denumirea pantofilor pe care ii cautati: ")
            lista_pantofi = self.__service.afisare_dupa_denumire(denumire)
            for el in lista_pantofi:
                print(f"id: {el.get_id()}, {el.get_denumire()}, marimea: {el.get_marime()}, numar de perechi: {el.get_numar_perechi()}, pret: {el.get_pret()}, personalizare: {el.get_personalizare()}")
        except ValueError:
            print("Date invalide!")
        except RepoError as v:
            print(v)

    def _ui_comandare(self):
        try:
            id = int(input("ID-ul pantofilor pe care ii doriti: "))
            pantofi = self.__service.comandare(id)
            for pantof in pantofi:
                print(f"{pantof.get_denumire()}: sunt disponibile {pantof.get_numar_perechi()} perechi de marimea {pantof.get_marime()}")
        except ValueError:
            print("Date invalide!")
        except RepoError as v:
            print(v)

    def run(self):
        while True:
            print("---")
            print("1. Afiseaza pantofii ce au aceeasi denumire si pot fi personalizati")
            print("2. Comandati pantofi dupa id")
            print("---")
            optiune = input("Optiunea: ")
            match optiune:
                case '1':
                    print("---")
                    self._ui_afisare()
                    print("---")
                case '2':
                    print("---")
                    self._ui_comandare()
                    print("---")
                case 'exit':
                    return
                case other:
                    continue
