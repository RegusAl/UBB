from domain.contact import Contact


class AgendaService:

    def __init__(self, repository, validator):
        self.__repository = repository
        self.__validator = validator

    def adauga_contact(self, id, nume, nrTelefon, grup):
        '''
        Functia adauga un contact nou in fisier.
        :param id: id-ul contactului (int)
        :param nume: numele contactului (string)
        :param nrTelefon: numarul de telefon (int)
        :param grup: grupul contactului (string)
        :return: -
        :raises: ValueError: daca numele este vid, daca grupul nu este valid
        '''
        contact = Contact(id, nume, nrTelefon, grup)
        self.__validator.validate(contact)
        agenda = self.__repository.load_from_file()
        for el in agenda:
            if nume == el.get_nume():
                raise ValueError("Numele deja exista!")
        agenda.append(contact)
        self.__repository.save_to_file(agenda)

    def cautare_numar_telefon(self, nume):
        '''
        Functia cauta un contact in functie de numele dat ca parametru
        :param nume: numele contactului cautat (string)
        :return: contactul (obiect)
        :raises: ValueError: daca numele nu exista
        '''
        for el in self.__repository.load_from_file():
            if el.get_nume() == nume:
                return el
        raise ValueError("Nu exista informatii pentru numele dat!")

    def sortare_grup(self, grup):
        '''
        Functia sorteaza grupul dat ca parametru in functie de nume
        :param grup: grupul (string)
        :return: datele de contact ce apartin grupului, sortate dupa nume (lista de obiecte)
        :raises ValueError: daca nu exista contacte in grup
        '''
        date_grup = self.__repository.get_grup(grup)
        if len(date_grup) == 0:
            raise ValueError("Nu exista contacte in acest grup!")
        date_grup.sort(key = lambda x: x.get_nume(), reverse = False)
        return date_grup

    def export(self, grup):
        '''
        Functia da export la contactele ce fac parte din grupul transmis ca parametru
        :param grup: grupul contactelor
        :return: -
        '''
        date_grup = self.__repository.get_grup(grup)
        with open(f"{grup}.txt", 'w') as f:
            for el in date_grup:
                string = str(el.get_nume()) + ',' + str(el.get_nrTelefon()) + '\n'
                f.write(string)
        f.close()