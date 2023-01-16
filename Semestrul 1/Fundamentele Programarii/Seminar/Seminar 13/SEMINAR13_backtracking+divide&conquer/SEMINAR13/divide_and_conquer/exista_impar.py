def exists_odd_in_list(lst):
    if len(lst) == 0:
        return False
    if len(lst) == 1:
        return lst[0] % 2 == 1
    middle = len(lst) // 2
    return exists_odd_in_list(lst[:middle]) or exists_odd_in_list(lst[middle:])


def test_exists_odd():
    l1 = []
    l2 = [2]
    l3 = [1]
    l4 = [1, 2, 3]
    l5 = [2, 1]
    l6 = [2, 2, 2, 2]
    l7 = [1, 1, 1, 1]

    assert (exists_odd_in_list(l1) == False)
    assert (exists_odd_in_list(l2) == False)
    assert (exists_odd_in_list(l3) == True)
    assert (exists_odd_in_list(l4) == True)
    assert (exists_odd_in_list(l5) == True)
    assert (exists_odd_in_list(l6) == False)
    assert (exists_odd_in_list(l7) == True)
