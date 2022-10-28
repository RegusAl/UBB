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
