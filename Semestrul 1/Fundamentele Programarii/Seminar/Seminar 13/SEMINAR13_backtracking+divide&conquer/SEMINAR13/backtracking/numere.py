import numpy as np


def get_sum(x):
    return np.array(x).sum()


def is_consistent(x, n, s):
    if x[0] == 0:
        return False
    if len(x) > n:
        return False
    if get_sum(x) > s:
        return False
    for i in range(1, len(x)):
        if (0 == x[i] % 2 == x[i - 1] % 2) or (x[i] % 2 == x[i - 1]%2 == 1):
            return False
    return True


def is_solution(x, n, s):
    return len(x) == n and get_sum(x) == s


def back_rec(x, n, s, solutions):
    x.append(-1)
    for i in range(10):
        x[-1] = i
        if is_consistent(x, n, s):
            if is_solution(x, n, s):
                print(''.join([str(i) for i in x]))
                solutions.append(''.join([str(i) for i in x]))
            back_rec(x[:], n, s, solutions)


def back_iter(n, s):
    x = [-1]
    solutions = []
    while len(x) > 0:
        chosen = False
        while not chosen and x[-1] < 9:
            x[-1] += 1
            chosen = is_consistent(x, n, s)
        if chosen:
            if is_solution(x, n, s):
                print(''.join([str(i) for i in x]))
                solutions.append(''.join([str(i) for i in x]))
            x.append(-1)
        else:
            x.pop()
    return solutions


n = 4
s = 8
solutions_rec = []
back_rec([], n, s, solutions_rec)
print('-----------')
solutions_iter = back_iter(n, s)

assert (solutions_iter == solutions_rec)
