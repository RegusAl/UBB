def create_tv_show(titlu, an_aparitie, eps):
    """
    Creeaza un serial
    :param titlu: titlul serialului
    :type titlu: string
    :param an_aparitie: anul de aparitie al serialului
    :type an_aparitie: int
    :param eps: numarul de episoade difuzate
    :type eps: int
    :return: serialul creat
    :rtype: dict (chei: titlu, an_aparitie, eps)
    """
    return {'titlu': titlu, 'an_aparitie': an_aparitie, 'eps': eps}


def validate_show(show):
    """
    Verifica daca un show este valid
    :param show: obiect de tip show
    :type show: dict
    :return:
    :rtype:
    :raises: ValueError daca serialul dat este invalid
    """
    # sa se verifice ca numele are mult de 2 caractere,
    # anul aparitiei este intre 1970-2021, iar numarul de episoade este un numar natural pozitiv
    errors = []
    if get_titlu(show)=='':
        errors.append('Titlul serialului trebuie sa aiba mai mult de 2 caractere.')
    if get_an_aparitie(show) < 1900 or get_an_aparitie(show) > 2021:
        errors.append('Anul aparitiei trebuie sa fie intre 1970-2021.')
    if get_episoade(show) <= 0:
        errors.append('Numarul de episoade trebuie sa fie mai mare de 0.')

    if len(errors) > 0:
        errors_string = '\n'.join(errors)
        raise ValueError(errors_string)


def is_same_show(show1, show2):
    """
    Verifica daca 2 seriale sunt identice
    :param show1: primul serial
    :type show1: obiect de tip serial (dict)
    :param show2: al doilea serial
    :type show2: obiect de tip serial (dict)
    :return: True daca serialele sunt identice (acelasi titlu, acelasi an de aparitie), Fals altfel
    :rtype: bool
    """
    if get_titlu(show1) == get_titlu(show2) and get_an_aparitie(show1) == get_an_aparitie(show2):
        return True
    return False

# getters
def get_titlu(show):
    return show['titlu']


def get_an_aparitie(show):
    return show['an_aparitie']


def get_episoade(show):
    return show['eps']


# setters
def set_titlu(show, new_title):
    show['titlu'] = new_title


def set_no_eps(show, new_no_eps):
    show['eps'] = new_no_eps


def set_an_aparitie(show, new_an_ap):
    show['an_aparitie'] = new_an_ap


def test_create_show():
    show1 = create_tv_show('Supernatural', 2005, 327)
    assert (type(show1) == dict)
    assert (get_titlu(show1) == 'Supernatural')
    assert (get_an_aparitie(show1) == 2005)
    assert (get_episoade(show1) == 327)

    # cand se vorbeste de date introduse invalid
    # vor trebui teste si pentru acele cazuri cu
    # exceptii


def test_validate_show():
    show1 = create_tv_show('', 2005, 327)
    try:
        validate_show(show1)
        assert False
    except ValueError as ve:
        assert (str(ve) == 'Titlul serialului trebuie sa aiba mai mult de 2 caractere.')

    show2 = create_tv_show('Supernatural', 2022, 327)
    try:
        validate_show(show2)
        assert False
    except ValueError as ve:
        assert (str(ve) == 'Anul aparitiei trebuie sa fie intre 1970-2021.')

    show3 = create_tv_show('Supernatural', 2005, -77)
    try:
        validate_show(show3)
        assert False
    except ValueError as ve:
        assert (str(ve) == 'Numarul de episoade trebuie sa fie mai mare de 0.')

    show4 = create_tv_show('', 2005, -2)
    try:
        validate_show(show4)
        assert False
    except ValueError as ve:
        assert (
                str(ve) == 'Titlul serialului trebuie sa aiba mai mult de 2 caractere.\nNumarul'
                           ' de episoade trebuie sa fie mai mare de 0.')


def test_is_same_show():
    show1 = create_tv_show('Supernatural', 2005, 327)
    show2 = create_tv_show('Supernatural', 2005, 327)
    assert (is_same_show(show1, show2) == True)

    show3 = create_tv_show('Supernatural', 2008, 327)
    assert (is_same_show(show1, show3) == False)

    show4 = create_tv_show('Suits', 2005, 327)
    assert (is_same_show(show1, show4) == False)

    show5 = create_tv_show('Suits', 2013, 176)
    assert (is_same_show(show1, show5) == False)

