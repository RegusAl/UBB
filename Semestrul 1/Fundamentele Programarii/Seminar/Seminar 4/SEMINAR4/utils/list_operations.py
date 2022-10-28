def make_dict_list_copy(lst):
    """
    Face o copie la o lista de dictionare
    :param lst: lista care se copiaza
    :type lst: list (of dicts)
    :return: copie a listei date
    :rtype: list (of dicts)
    """
    cpy = []
    for el in lst:
        crt_elem_dict = {}
        for key, value in el.items():
            crt_elem_dict[key] = value
        cpy.append(crt_elem_dict)

    return cpy


def add_to_list(the_list, elem):
    """
    Adauga un element la o lista
    :param the_list: lista la care se adauga
    :type the_list: list
    :param elem: elementul care se adauga
    :type elem: any
    :return: lista data se modifica prin adaugarea noului element
    :rtype: -;
    """
    the_list.append(elem)


# se poate implementa si remove, si filter mai general
# si sa le introducem  in acest modul
# respectiv sa le folosim in show_manager

def test_copy_list():
    test_list1 = [{'a': 10, 'b': 15}, {'t': 20}]
    copy_test_list = make_dict_list_copy(test_list1)

    # == intre liste verifica daca listele sunt egale
    # element cu element (conteaza ordinea)
    assert (test_list1 == copy_test_list)


def test_add_to_list():
    test_list = []
    add_to_list(test_list, 7423)
    assert (len(test_list) == 1)

    test_list1 = [{'a': 10, 'b': 15}, {'t': 20}]
    add_to_list(test_list1, {'d': 17412})

    assert (len(test_list1) == 3)
    assert (test_list1[2]['d'] == 17412)
