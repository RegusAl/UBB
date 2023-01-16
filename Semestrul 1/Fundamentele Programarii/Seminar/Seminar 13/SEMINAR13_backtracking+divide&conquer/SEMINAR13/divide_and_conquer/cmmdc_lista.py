import math


def cmmdc_lista(lst):
    if len(lst) == 0:
        return None
    if len(lst) == 1:
        return lst[0]
    return math.gcd(lst[0], cmmdc_lista(lst[1:]))


def test_cmmdc_lista():
    l1 = []
    l2 = [1, 2, 3]
    l3 = [2, 4, 6, 8]
    l4 = [36, 24, 48]
    l5 = [24, 48]
    l6 = [0, 100]
    l7 = [100, 250, 300]

    assert (cmmdc_lista(l1) is None)
    assert (cmmdc_lista(l2) == 1)
    assert (cmmdc_lista(l3) == 2)
    assert (cmmdc_lista(l4) == 12)
    assert (cmmdc_lista(l5) == 24)
    assert (cmmdc_lista(l6) == 100)
    assert (cmmdc_lista(l7) == 50)
