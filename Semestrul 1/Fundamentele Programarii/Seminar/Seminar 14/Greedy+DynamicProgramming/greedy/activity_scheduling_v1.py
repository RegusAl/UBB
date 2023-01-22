import math
import random


def select_most_promising(c):
    """
    Selecteaza activitatea care se termina cel mai repede din lista data
    :param c: multimea candidat
    :type c: list of tuples
    :return: activitatea care se termina cel mai devreme
    :rtype: tuple
    """
    min_end_time = math.inf
    min_tuple = (-math.inf, -math.inf)
    for start_time, end_time in c:
        if end_time < min_end_time:
            min_end_time = end_time
            min_tuple = (start_time, end_time)
    return min_tuple


def is_solution(b):
    return len(b) >= 1


def is_acceptable(b):
    """
    Verifica daca b contine activitati compatibile
    :param b: solutia partiala de verificat
    :type b: list of tuples
    :return: True daca activitatile sunt compatibile, fals altfel
    :rtype: bool
    """
    if len(b) == 1:
        return True
    end_time_second_to_last_activity = b[-2][1]
    start_time_last_activity = b[-1][0]
    return start_time_last_activity >= end_time_second_to_last_activity


def greedy(c):
    """
    Determina multimea maximala de activitati din c
    :param c: multimea candidat
    :type c: list of tuples
    :return: multimea maximala de activitati
    :rtype: list of tuples
    """
    b = []
    while len(c) > 0:
        crt_candidate = select_most_promising(c)
        c.remove(crt_candidate)
        if is_acceptable(b + [crt_candidate]):
            b.append(crt_candidate)

    if is_solution(b):
        return b
    return None


def test_activity_scheduling1():
    c1 = [(10, 20), (12, 25), (20, 30)]
    random.shuffle(c1)
    assert (greedy(c1) == [(10, 20), (20, 30)])

    c2 = [(1, 2), (3, 4), (0, 6), (5, 7), (8, 9), (5, 9)]
    random.shuffle(c2)
    assert (greedy(c2) == [(1, 2), (3, 4), (5, 7), (8, 9)])

    c3 = [(1, 2), (1, 4), (1, 3)]

    # raspunsul e 1 activitate - oricare ar fi raspuns corect
    # implementarea curenta returneaza [(1,2)]
    assert (greedy(c3) == [(1, 2)])

    activity_set = [(1, 3), (2, 5), (4, 8)]
    print(greedy(activity_set) == [(1, 3), (4, 8)])

    activity_set2 = [(1, 4), (3, 5), (0, 6), (5, 7), (3, 8), (5, 9), (6, 10), (8, 11), (8, 12), (2, 13), (12, 14)]
    assert (greedy(activity_set2) == [(1, 4), (5, 7), (8, 11), (12, 14)])
