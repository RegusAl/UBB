def is_consistent(x, n):
    if len(x) > n:
        return False
    if len(x) != len(set(x)):
        return False
    for i in range(1, len(x), 2):
        if x[i] != i + 1:
            return False
    return True


def is_solution(x, n):
    return len(x) == n


def back_rec(x, n):
    x.append(-1)
    for i in range(1, n + 1):
        x[-1] = i
        if is_consistent(x, n):
            if is_solution(x, n):
                print(x)
            back_rec(x[:], n)


def back_iter(n):
    x = [0]
    while len(x) > 0:
        chosen = False
        while not chosen and x[-1] < n:
            x[-1] += 1
            chosen = is_consistent(x, n)
        if chosen:
            if is_solution(x, n):
                print(x)
            x.append(0)
        else:
            x.pop()


back_rec([], 5)
print('-------')
back_iter(5)
