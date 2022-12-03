from domain.entities import Serial
from exceptions.exceptions import DuplicateIDException, ShowNotFoundException


class ShowInMemoryRepo:
    def __init__(self):
        # {idSerial1: Serial1, idSerial2: Serial2}
        self.__shows = {}

    def find(self, id):
        """
        Cauta serialul cu id dat
        :param id: id dat
        :type id: str
        :return: serialul cu id dat, None daca nu exista serial cu id dat
        :rtype: Serial
        """
        if id in self.__shows:
            return self.__shows[id]
        return None

    def store(self, show):
        """
       Adauga un serial in lista
       :param show: serialul care se adauga
       :type show: Serial
       :return: -; lista de seriale se modifica prin adaugarea serialului dat
        :rtype:
        :raises: DuplicateIDException daca serialul exista deja
        """
        # verificare id duplicat
        if show.getId() in self.__shows:
            raise DuplicateIDException()

        self.__shows[show.getId()] = show

    def get_all(self):
        """
        Returneaza o lista cu toate show-urile existente
        :rtype: list of objects de tip Serial
        """
        return list(self.__shows.values())

    def size(self):
        """
        Returneaza numarul de seriale din multime
        :return: numar seriale existente
        :rtype:int
        """
        return len(self.__shows)

    def delete(self, id):
        """
        Sterge serial dupa id
        :param id: id-ul dat
        :type id: str
        :return: serialul sters
        :rtype: Serial
        :raises: ShowNotFoundException daca id-ul nu exista
        """
        if id not in self.__shows:
            raise ShowNotFoundException()

        deleted_show = self.__shows[id]
        del self.__shows[id]
        return deleted_show

    def update(self, id, modified_show):
        """
        Modifica datele serialului cu id dat
        :param id: id dat
        :type id: str
        :param modified_show: show-ul cu datele noi
        :type modified_show: Serial
        :return: show-ul modificat
        :rtype: Serial
        """

        if id not in self.__shows:
            raise ShowNotFoundException()

        old_show = self.__shows[id]
        self.__shows[id] = modified_show
        return modified_show

    def delete_all(self):
        self.__shows = {}



class ShowFileRepo:
    def __init__(self, filename):
        self.__filename = filename

    def __load_from_file(self):
        """
        Incarca datele din fisier
        :return: lista de seriale din fisier
        :rtype: list of Serial objects
        :raises: ...
        """
        try:
            f = open(self.__filename, 'r')
            # f = io.open(self.__filename, mode='r', encoding='utf-8')
        except IOError:
            return

        lines = f.readlines()
        # lines: ['C1001;Superstore;2019;98', 'F1001; Arrow;2012;170',...]
        all_shows = []
        for line in lines:
            show_id, show_name, show_year, show_eps = [token.strip() for token in line.split(';')]
            show_year = int(show_year)
            show_eps = int(show_eps)

            s = Serial(show_id, show_name, show_year, show_eps)
            all_shows.append(s)

        f.close()
        return all_shows

    def __save_to_file(self, all_shows):
        """
        Salveaza serialele in fisier
        """
        with open(self.__filename, 'w') as f:
            for show in all_shows:
                show_string = str(show.getId()) + ';' + str(show.getTitle()) + ';' + str(
                    show.getAnAparitie()) + ';' + str(show.getEpisoade()) + '\n'
                f.write(show_string)

    def find(self, id):
        """
        Cauta serialul cu id dat
        :param id: id dat
        :type id: str
        :return: serialul cu id dat, None daca nu exista serial cu id dat
        :rtype: Serial
        """
        all_shows = self.__load_from_file()
        for show in all_shows:
            if show.getId() == id:
                return show
        return None

    def store(self, show):
        """
       Adauga un serial in lista
       :param show: serialul care se adauga
       :type show: Serial
       :return: -; lista de seriale se modifica prin adaugarea serialului dat
        :rtype:
        :raises: DuplicateIDException daca serialul exista deja
        """
        all_shows = self.__load_from_file()
        if show in all_shows:
            raise DuplicateIDException()

        all_shows.append(show)
        self.__save_to_file(all_shows)

    def get_all(self):
        """
        Returneaza o lista cu toate show-urile existente
        :rtype: list of objects de tip Serial
        """
        return self.__load_from_file()

    def size(self):
        """
        Returneaza numarul de seriale din multime
        :return: numar seriale existente
        :rtype:int
        """
        return len(self.__load_from_file())

    def __find_index(self, all_shows, id):
        """
        Gaseste pozitia in lista a serialului cu id dat
        :param all_shows: lista cu toate serialele
        :type all_shows: list of Serial objects
        :param id: id-ul cautat
        :type id: str
        :return: pozitia in lista a serialului dat, -1 daca serialul nu se regaseste in lista
        :rtype: int, >=0, <repo.size()
        """
        index = -1
        for i in range(len(all_shows)):
            if all_shows[i].getId() == id:
                index = i

        return index

    def delete(self, id):
        """
        Sterge serial dupa id
        :param id: id-ul dat
        :type id: str
        :return: serialul sters
        :rtype: Serial
        :raises: ShowNotFoundException daca id-ul nu exista
        """
        all_shows = self.__load_from_file()
        index = self.__find_index(all_shows, id)
        if index == -1:
            raise ShowNotFoundException()

        deleted_show = all_shows.pop(index)

        self.__save_to_file(all_shows)
        return deleted_show

    def update(self, id, modified_show):
        """
        Modifica datele serialului cu id dat
        :param id: id dat
        :type id: str
        :param modified_show: show-ul cu datele noi
        :type modified_show: Serial
        :return: show-ul modificat
        :rtype: Serial
        :raises: ShowNotFoundException daca nu exista serial cu id dat
        """

        all_shows = self.__load_from_file()
        index = self.__find_index(all_shows, id)
        if index == -1:
            raise ShowNotFoundException()

        all_shows[index] = modified_show

        self.__save_to_file(all_shows)
        return modified_show

    def delete_all(self):
        self.__save_to_file([])


class ShowRepoFileInheritance(ShowInMemoryRepo):
    def __init__(self, filename):
        ShowInMemoryRepo.__init__(self)
        self.__filename = filename
        self.__load_from_file()

    def __load_from_file(self):
        """
        Incarca datele din fisier
        :return: lista de seriale din fisier
        :rtype: list of Serial objects
        :raises: ...
        """
        try:
            f = open(self.__filename, 'r')
            # f = io.open(self.__filename, mode='r', encoding='utf-8')
        except IOError:
            return

        lines = f.readlines()
        # lines: ['C1001;Superstore;2019;98', 'F1001; Arrow;2012;170',...]
        for line in lines:
            show_id, show_name, show_year, show_eps = [token.strip() for token in line.split(';')]
            show_year = int(show_year)
            show_eps = int(show_eps)

            s = Serial(show_id, show_name, show_year, show_eps)
            ShowInMemoryRepo.store(self, s)

        f.close()

    def __save_to_file(self):
        all_shows = ShowInMemoryRepo.get_all(self)
        with open(self.__filename, 'w') as f:
            for show in all_shows:
                show_string = str(show.getId()) + ';' + str(show.getTitle()) + ';' + str(
                    show.getAnAparitie()) + ';' + str(show.getEpisoade()) + '\n'
                f.write(show_string)

    def find(self, id):
        """
        Cauta serialul cu id dat
        :param id: id dat
        :type id: str
        :return: serialul cu id dat, None daca nu exista serial cu id dat
        :rtype: Serial
        """
        return ShowInMemoryRepo.find(self, id)

    def store(self, show):
        """
       Adauga un serial in lista
       :param show: serialul care se adauga
       :type show: Serial
       :return: -; lista de seriale se modifica prin adaugarea serialului dat
        :rtype:
        :raises: DuplicateIDException daca serialul exista deja
        """
        ShowInMemoryRepo.store(self, show)
        self.__save_to_file()

    def get_all(self):
        """
        Returneaza o lista cu toate show-urile existente
        :rtype: list of objects de tip Serial
        """
        return ShowInMemoryRepo.get_all(self)

    def size(self):
        """
        Returneaza numarul de seriale din multime
        :return: numar seriale existente
        :rtype:int
        """
        return ShowInMemoryRepo.size(self)

    def delete(self, id):
        """
        Sterge serial dupa id
        :param id: id-ul dat
        :type id: str
        :return: serialul sters
        :rtype: Serial
        :raises: ShowNotFoundException daca id-ul nu exista
        """
        deleted_show = ShowInMemoryRepo.delete(self, id)
        self.__save_to_file()
        return deleted_show

    def update(self, id, modified_show):
        """
        Modifica datele serialului cu id dat
        :param id: id dat
        :type id: str
        :param modified_show: show-ul cu datele noi
        :type modified_show: Serial
        :return: show-ul modificat
        :rtype: Serial
        :raises: ShowNotFoundException daca nu exista serial cu id dat
        """
        updated_show = ShowInMemoryRepo.update(self, id, modified_show)
        self.__save_to_file()
        return updated_show

    def delete_all(self):
        ShowInMemoryRepo.delete_all(self)
        self.__save_to_file()
