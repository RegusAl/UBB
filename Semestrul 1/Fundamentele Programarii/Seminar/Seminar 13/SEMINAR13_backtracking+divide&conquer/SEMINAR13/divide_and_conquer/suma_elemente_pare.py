def sum_of_even(lst):
    if len(lst) == 0:
        return 0
    if len(lst) == 1:
        if lst[0] % 2 == 0:
            return lst[0]
        else:
            return 0
    middle = len(lst) // 2
    return sum_of_even(lst[:middle]) + sum_of_even(lst[middle:])


def sum_of_even2(lst):
    if len(lst) == 0:
        return 0
    if len(lst) == 1:
        if lst[0] % 2 == 0:
            return lst[0]
        else:
            return 0
    if lst[0] % 2 == 0:
        return lst[0] + sum_of_even2(lst[1:])
    else:
        return sum_of_even2(lst[1:])


def test_sum_array_even():
    l1 = []
    l2 = [1]
    l3 = [1, 1, 1]
    l4 = [2]
    l5 = [2, 2, 2, 2, 2]
    l6 = [1, 2, 3, 4, 5, 6]
    l7 = [1, 2, 3, 4, 5]

    assert (sum_of_even(l1) == 0)
    assert (sum_of_even(l2) == 0)
    assert (sum_of_even(l3) == 0)
    assert (sum_of_even(l4) == 2)
    assert (sum_of_even(l5) == 10)
    assert (sum_of_even(l6) == 12)
    assert (sum_of_even(l7) == 6)
