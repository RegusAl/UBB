def acceptabil(b):
    if len(b) == 1:
        return True
    if b[-1][0] >= b[-2][1]:
        return True
    return False


def greedy(c):
    b = []
    # sorteaza descrescator dupa momentul de sfarsit al activitatilor
    c = sorted(c, key=lambda tuplu: tuplu[1], reverse=True)
    while c != []:
        candidate = c.pop()
        if acceptabil(b + [candidate]):
            b.append(candidate)

    return b


def test_activity_scheduling1():
    c1 = [(10, 20), (12, 25), (20, 30)]
    assert (greedy(c1) == [(10, 20), (20, 30)])

    c2 = [(1, 2), (3, 4), (0, 6), (5, 7), (8, 9), (5, 9)]
    assert (greedy(c2) == [(1, 2), (3, 4), (5, 7), (8, 9)])

    c3 = [(1, 2), (1, 4), (1, 3)]

    # raspunsul e 1 activitate - oricare ar fi raspuns corect
    # implementarea curenta returneaza [(1,2)]
    assert (greedy(c3) == [(1, 2)])
