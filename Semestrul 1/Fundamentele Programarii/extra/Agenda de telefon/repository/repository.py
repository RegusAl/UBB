from domain.contact import Contact


class ContactRepository:

    def __init__(self, filename):
        self.__filename = filename

    def load_from_file(self):
        '''
        Functia preia din fisier contactele
        :return: lista de obiecte de tip 'Contact'
        '''
        agenda = []
        with open(self.__filename, 'r') as f:
            lines = f.readlines()
            for line in lines:
                if line != '':
                    line = line.strip()
                    id, nume, nrTelefon, grup = line.split(';')
                    contact = Contact(int(id), nume, int(nrTelefon), grup)
                    agenda.append(contact)
            f.close()
        return agenda

    def save_to_file(self, agenda):
        '''
        Functia salveaza o lista de obiecte de tip Contact in fisier
        :param agenda: lista de obiecte de tip Contact
        :return: -
        '''
        with open(self.__filename, 'w') as f:
            for el in agenda:
                string = str(el.get_id()) + ';' + str(el.get_nume()) + ';' + str(el.get_nrTelefon()) + ';' + str(el.get_grup()) + '\n'
                f.write(string)
        f.close()

    def get_grup(self, grup):
        '''
        Functia cauta in fisier contactele cu acelasi grup
        :param grup: grupul cautat
        :return: lista de obiecte de tip Contact ce apartin grupului dat ca parametru
        '''
        date_grup = []
        for el in self.load_from_file():
            if el.get_grup() == grup:
                date_grup.append(el)
        return date_grup