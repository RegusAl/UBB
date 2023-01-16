import math


def is_prime(x):
    if x < 2:
        return False
    if x == 2:
        return True
    if x % 2 == 0:
        return False
    for d in range(2, int(math.sqrt(x))):
        if x % d == 0:
            return False
    return True


def max_prime_from_list(lst):
    # base case
    if len(lst) == 0:
        return -1
    if len(lst) == 1:
        if is_prime(lst[0]):
            return lst[0]
        else:
            return -1
    middle = len(lst) // 2
    return max(max_prime_from_list(lst[:middle]), max_prime_from_list(lst[middle:]))


def test_max_prime_from_list():
    l1 = []
    l2 = [1]
    l3 = [1, 2]
    l4 = [3, 5, 7]
    l5 = [1, 1, 2, 3, 4, 5, 6, 100]
    l6 = [100, 102, 104]
    l7 = [17]

    assert (max_prime_from_list(l1) == -1)
    assert (max_prime_from_list(l2) == -1)
    assert (max_prime_from_list(l3) == 2)
    assert (max_prime_from_list(l4) == 7)
    assert (max_prime_from_list(l5) == 5)
    assert (max_prime_from_list(l6) == -1)
    assert (max_prime_from_list(l7) == 17)
