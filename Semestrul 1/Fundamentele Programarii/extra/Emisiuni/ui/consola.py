from erori.erori import RepoError, BlocatError

class Consola:

    def __init__(self, service, repository):
        self.__service = service
        self.__repo = repository

    def ui_afisare_emisiuni(self):
        '''
        Functia ui ce afiseaza emisiunile
        :return: -
        '''
        lista = self.__service.get_all()
        for el in lista:
            print(f'{el.get_nume()}({el.get_tip()}) dureaza {el.get_durata()} ore - {el.get_descriere()}')

    def ui_stergere_emisiune(self):
        '''
        Functia ui ce sterge emisiunile in functie de numele si tipul dat de utilizator
        :return: -
        :raise: ValueError: daca datele introduse sunt invalide
        :raise: RepoError: daca emisiunea nu exista
        :raise: BlocatError: daca emisiunea a fost blocata
        '''
        try:
            nume = input("Numele emisiunii: ")
            tip = input("Tipul emisiunii: ")
            self.__service.stergere_emisiune(nume, tip)
        except ValueError:
            print("Datele introduse sunt invalide")
        except RepoError as re:
            print(re)
        except BlocatError as be:
            print(be)

    def ui_modifica_emisiune(self):
        '''
        Functia ui ce modifica emisiunea prin schimbarea duratei si a descrierii date de utilizator
        :return: -
        :raise: ValueError: daca datele introduse sunt invalide
        :raise: RepoError: daca emisiunea nu exista
        :raise: BlocatError: daca emisiunea a fost blocata
        '''
        try:
            nume = input("Numele emisiunii: ")
            tip = input("Tipul emisiunii: ")
            durata = int(input("Durata emisiunii: "))
            descriere = input("Descrierea emisiunii: ")
            self.__service.modificare_emisiune(nume, tip, durata, descriere)
        except ValueError:
            print("Datele introduse sunt invalide")
        except RepoError as re:
            print(re)
        except BlocatError as be:
            print(be)

    def ui_program_random(self):
        '''
        Functia ui ce afiseaza un program TV random in functie de ora de inceput si ora de sfarsit
        :return: -
        :raise: ValueError: daca datele date de utilizator sunt invalide
        '''
        try:
            ora_inceput = int(input("Ora inceput: "))
            ora_sfarsit = int(input("Ora sfarsit: "))
            program = self.__service.program_random(ora_inceput, ora_sfarsit)
            print("ORA\t\tNUME\t\tTIP\t\tDescriere")
            ora = ora_inceput
            for el in program:
                print(f"{ora}\t\t{el.get_nume()}\t\t{el.get_tip()}\t\t{el.get_descriere()}")
                ora += el.get_durata()
        except ValueError:
            print("Datele introduse sunt invalide")

    def ui_blocare_tip(self):
        '''
        Functia ui ce blocheaza un tip de emisiune dat de utilizator
        :return: -
        :raises: ValueError: daca datele introduse sunt invalide
        '''
        try:
            # print(f'tipurile blocate pana acum: {self.__service.blocare_tip("")}')
            tip = input("Tipul de emisiune pe care il vreti blocat: ")
            self.__service.blocare_tip(tip)
        except ValueError:
            print("Datele inntroduse sunt invalide!")

    def ui_tipuri_blocate(self):
        '''
        Functia ui ce afiseaza tipurile de emisiuni blocate
        :return: -
        '''
        tipuri_blocate = self.__service.tipuri_blocate()
        if len(tipuri_blocate) == 0:
            print('Nu exista niciun tip blocat!\n')
        else:
            for tip in tipuri_blocate:
                print(tip)
            print('\n')

    def ui_deblocheaza_tip(self):
        '''
        Functia ui ce deblocheaza un tip de emisiune TV dat de utilizator
        :return: -
        '''
        tip = input('Introduceti tipul pe care doriti sa il deblocati: ')
        tipuri_blocate = self.__service.tipuri_blocate()
        if tip not in tipuri_blocate:
            print('Tipul nu e blocat!\n')
        else:
            self.__service.deblocheaza_tip(tip)
            print('Tipul a fost deblocat!\n')

    def ui_deblocheaza_tot(self):
        '''
        Functia ui ce deblocheaza toate tipurile de emisiuni TV ce sunt blocate
        :return: -
        '''
        tipuri_blocate = self.__service.tipuri_blocate()
        if len(tipuri_blocate) == 0:
            print('Nu exista niciun tip blocat!\n')
        else:
            self.__service.deblocheaza_tot()
            print('Toate tipurile au fost deblocate!\n')

    def meniu_blocare(self):
        print("1. Blocheaza tip")
        print("2. Deblocheaza tip")
        print("3. Afisare tipuri blocate")
        print("4. Deblocheaza tot")
        optiune = input()
        match optiune:
            case '1':
                self.ui_blocare_tip()
            case '2':
                self.ui_deblocheaza_tip()
            case '3':
                self.ui_tipuri_blocate()
            case '4':
                self.ui_deblocheaza_tot()
            case other:
                return



    def run(self):
        while True:
            optiune = input("Optiunea dumneavoastra: ")
            match optiune:
                case '1':
                    print("Stergere Emisiune")
                    self.ui_stergere_emisiune()
                case '2':
                    print("Modifica Emisiune")
                    self.ui_modifica_emisiune()
                case '3':
                    print("Program")
                    self.ui_program_random()
                case '4':
                    print("Blocare")
                    self.meniu_blocare()
                case 'afisare':
                    self.ui_afisare_emisiuni()
                case 'x':
                    return
                case other:
                    pass