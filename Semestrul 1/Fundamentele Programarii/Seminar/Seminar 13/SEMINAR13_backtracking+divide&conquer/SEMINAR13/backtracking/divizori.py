import numpy as np


def get_product(x):
    x_nparr = np.array(x)
    return x_nparr.prod()


def is_consistent(x, n):
    if x != sorted(x):
        return False
    if get_product(x) > n:
        return False

    return True


def is_solution(x, n):
    return get_product(x) == n


def back_rec_divizori(x, n, divizori):
    x.append(-1)
    for d in divizori:
        x[-1] = d
        if is_consistent(x, n):
            if is_solution(x, n):
                print(x)
            back_rec_divizori(x[:], n, divizori)


def back_iter_divizori(n):
    x = [1]
    while len(x) > 0:
        chosen = False
        while not chosen and x[-1] < n - 1:
            x[-1] += 1
            chosen = is_consistent(x,n)
        if chosen:
            if is_solution(x,n):
                print(x)
            x.append(1)
        else:
            x.pop()

number = 30
back_rec_divizori([], number, [d for d in range(2, number) if number % d == 0])
print('----------')
back_iter_divizori(number)