from domain.show import create_tv_show, get_an_aparitie, get_episoade, validate_show, is_same_show
from utils.list_operations import make_dict_list_copy, add_to_list


def generate_shows():
    # 2000-2010: 4
    # 2018-2020: 2

    # 300: 1
    # 150: 5
    # 80: 7
    # 5: lungimea listei

    return [{'titlu': "The Walking Dead", 'an_aparitie': 2010, 'eps': 177},
            {'titlu': "Outlander", 'an_aparitie': 2014, 'eps': 87},
            {'titlu': "Supernatural", 'an_aparitie': 2005, 'eps': 327},
            {'titlu': "The Witcher", 'an_aparitie': 2019, 'eps': 8},
            {'titlu': "Ozark", 'an_aparitie': 2017, 'eps': 30},
            {'titlu': "Brooklyn Nine-Nine", 'an_aparitie': 2013, 'eps': 153},
            {'titlu': "New Amsterdam", 'an_aparitie': 2018, 'eps': 61},
            {'titlu': "The Good Place", 'an_aparitie': 2016, 'eps': 50},
            {'titlu': "Burn Notice", 'an_aparitie': 2007, 'eps': 111},
            {'titlu': "Strike Back", 'an_aparitie': 2010, 'eps': 77},
            {'titlu': "Stargate SG-1", 'an_aparitie': 1997, 'eps': 214},
            {'titlu': "Charmed", 'an_aparitie': 1998, 'eps': 179},
            {'titlu': "Squid Game", 'an_aparitie': 2021, 'eps': 9}
            ]


def setup_show_manager(add_predefined):
    """
    Initializeaza un obiect de tip show manager
    :param add_predefined: indicator pentru adaugarea serialelor predefinite in lista curenta de seriale
            daca add_predefined==True se incepe cu o lista populata de seriale predefinite, altfel cu o lista
            goala de seriale
    :type add_predefined: bool
    :return: o lista cu 2 pozitii care reprezinta show_manager-ul, show_manager[0] - lista curenta de seriale
                    show_manager[1] = undo_list
    :rtype: list
    """
    if add_predefined:
        crt_show_list = generate_shows()
    else:
        crt_show_list = []

    undo_list = []
    return [crt_show_list, undo_list]


# getters
def get_show_list(show_manager):
    return show_manager[0]


def get_undo_list(show_manager):
    return show_manager[1]


# setters
def set_show_list(show_manager, new_show_list):
    show_manager[0] = new_show_list


def set_undo_list(show_manager, new_undo_list):
    show_manager[1] = new_undo_list


# functii care implementeaza partea de logica a programului pentru entitatea show_manager
def remove_shows_from_list(show_list, an_start, an_end):
    """
    Elimina din lista serialele cu an_aparitie intre anii dati
    :param show_list: lista de seriale
    :type show_list: list (of dicts)
    :param an_start: anul de inceput
    :type an_start: int
    :param an_end: anul de sfarsit
    :type an_end: int
    :return: lista cu serialele care au anul de aparitie <an_start, >an_end
    :rtype: list (of dicts)
    """
    new_list = [show for show in show_list if get_an_aparitie(show) < an_start or get_an_aparitie(show) > an_end]
    return new_list


def get_no_shows_more_episodes(show_list, no_eps):
    """
    Gaseste numarul de seriale cu numar de episoade mai mare decat numarul dat
    :param show_list: lista de seriale
    :type show_list: list (of dicts)
    :param no_eps: numarul de episoade dat
    :type no_eps: int
    :return: numarul de seriale cu numar episoade mai mare decat numarul dat
    :rtype: int
    """
    count_no_shows = 0
    for show in show_list:
        if get_episoade(show) > no_eps:
            count_no_shows += 1
    return count_no_shows


def exists_show(show_list, show):
    """
    Verifica daca show-ul dat exista deja in lista
    :param show_list: lista de seriale
    :type show_list: list (of dicts)
    :param show: serialul dat
    :type show: dict
    :return: True daca serialul exista deja in lista, False altfel
    :rtype: bool
    """
    for crt_show in show_list:
        if is_same_show(crt_show, show):
            return True
    return False


def add_show_to_manager(show_manager, titlu, an_aparitie, eps):
    """
    Adauga un show pentru a fi manageriat
    :param show_manager: obiect de tip show manager
    :type show_manager: list (len(show_manager)=2, show_manager[0] = lista crt de show-uri, show_manager[1] = lista de undo
    :param the_show: serialul care va fi adaugat
    :type the_show: dict
    :return: -; se modifica lista curenta de seriale prin adaugarea celui nou
    :rtype:
    :raises ValueError daca serialul pentru care se incearca adaugarea este invalid
    """
    show = create_tv_show(titlu, an_aparitie, eps)
    validate_show(show)

    crt_show_list = get_show_list(show_manager)
    if not exists_show(crt_show_list, show):
        undo_list = get_undo_list(show_manager)
        # .copy(), [:], fct proprie make_list_copy, deepCopy
        undo_list.append(make_dict_list_copy(crt_show_list))

        add_to_list(get_show_list(show_manager), show)
    else:
        raise ValueError('Serialul exista deja in lista.')



def delete_show_from_manager(show_manager, an_start, an_end):
    """
        Sterge seriale din lista pe baza anului de inceput
        :param show_manager: obiect de tip show manager
        :type show_manager: list (len(show_manager)=2, show_manager[0] = lista crt de show-uri, show_manager[1] = lista de undo
        :param an_start: anul de inceput al perioadei din care vrem sa stergem
        :type an_start: int
        :param an_end: anul de sfarsit al perioadei din care vrem sa stergem
        :type an_end: int
        :return: -; se modifica lista curenta de seriale prin stergerea serialelor din perioada an_start - an_end
        :rtype:
        """
    crt_show_list = get_show_list(show_manager)
    undo_list = get_undo_list(show_manager)

    # .copy(), [:], fct proprie make_list_copy, deepCopy
    undo_list.append(make_dict_list_copy(crt_show_list))

    set_show_list(show_manager, remove_shows_from_list(crt_show_list, an_start, an_end))


def undo(show_manager):
    """
    Face undo la ultima operatie de adaugare sau stergere
     :param show_manager: obiect de tip show manager
    :type show_manager: list (len(show_manager)=2, show_manager[0] = lista crt de show-uri, show_manager[1] = lista de undo
    :return: lista curenta de show-uri revine la starea de dinainte de ultima operatie
    :rtype: -;
    """
    undo_list = get_undo_list(show_manager)

    if len(undo_list) == 0:
        raise ValueError("Nu se mai poate face undo. ")
    else:
        previous_list = undo_list[-1]

        set_show_list(show_manager, previous_list)
        set_undo_list(show_manager, undo_list[:-1])


def test_remove_show_from_list():
    test_list = generate_shows()
    initial_length = len(test_list)

    test_list = remove_shows_from_list(test_list, 2000, 2010)
    assert (len(test_list) == initial_length - 4)
    assert (len([show for show in test_list if get_an_aparitie(show) >= 2000 and get_an_aparitie(show) <= 2010]) == 0)

    initial_length2 = len(test_list)
    test_list = remove_shows_from_list(test_list, 2018, 2020)
    assert (len(test_list) == initial_length2 - 2)
    assert (len([show for show in test_list if get_an_aparitie(show) >= 2018 and get_an_aparitie(show) <= 2020]) == 0)

    test_list = remove_shows_from_list(test_list, 1990, 2025)
    assert (len(test_list) == 0)


def test_no_shows():
    test_list = generate_shows()

    # 300: 1
    # 150: 5
    # 80: 7
    # 5: lungimea listei

    more_than_300 = get_no_shows_more_episodes(test_list, 300)
    assert (more_than_300 == 1)

    more_than_150 = get_no_shows_more_episodes(test_list, 150)
    assert (more_than_150 == 5)

    more_than_80 = get_no_shows_more_episodes(test_list, 80)
    assert (more_than_80 == 7)

    more_than_5 = get_no_shows_more_episodes(test_list, 5)
    assert (more_than_5 == len(test_list))


def test_add_show_to_manager():
    test_manager = setup_show_manager(False)

    add_show_to_manager(test_manager, 'See', 2019, 12)
    assert (len(get_show_list(test_manager)) == 1)

    add_show_to_manager(test_manager, 'Suits', 2011, 134)
    assert (len(get_show_list(test_manager)) == 2)

    try:
        add_show_to_manager(test_manager, '', 2011, 134)
        assert False
    except ValueError:
        assert True

    try:
        add_show_to_manager(test_manager, 'a', 886, -1)
        assert False
    except ValueError:
        assert True

    try:
        add_show_to_manager(test_manager, 'Suits', 2011, 134)
        assert False
    except ValueError:
        assert True


def test_delete_from_manager():
    test_manager = setup_show_manager(False)

    add_show_to_manager(test_manager, 'See', 2019, 12)
    add_show_to_manager(test_manager, 'Suits', 2011,134)
    add_show_to_manager(test_manager, 'The Walking Dead', 2010, 177)

    delete_show_from_manager(test_manager, 2009, 2012)
    assert (len(get_show_list(test_manager)) == 1)

    delete_show_from_manager(test_manager, 2018, 2021)
    assert (len(get_show_list(test_manager)) == 0)


def test_undo():
    # add
    test_manager = setup_show_manager(False)

    add_show_to_manager(test_manager, 'See', 2019, 12)
    assert (len(get_show_list(test_manager)) == 1)

    undo(test_manager)
    assert (len(get_show_list(test_manager)) == 0)

    # delete
    test_manager = setup_show_manager(True)
    initial_length = len(get_show_list(test_manager))

    delete_show_from_manager(test_manager, 2000, 2022)
    assert (len(get_show_list(test_manager)) == 2)

    undo(test_manager)
    assert (len(get_show_list(test_manager)) == initial_length)


def test_exists_show():
    test_manager = setup_show_manager(True)
    show = create_tv_show("The Walking Dead", 2010, 177)
    assert (exists_show(get_show_list(test_manager), show) == True)

    show1 = create_tv_show('ABC ABC', 2011, 29)
    assert (exists_show(get_show_list(test_manager), show1) == False)
