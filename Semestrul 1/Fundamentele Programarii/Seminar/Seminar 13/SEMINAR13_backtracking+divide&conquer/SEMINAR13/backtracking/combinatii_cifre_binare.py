def is_consistent(x, n):
    # if len(x) > 2 * n + 1:
    #     return False
    if len(x) <= 1:
        return True
    return not x[-1] == x[-2] == 1


def is_solution(x, n):
    return len(x) == 2 * n + 1


def output_solution(x):
    print(x)


def back_rec(x, n):
    x.append(-1)
    for i in range(2):
        x[-1] = i
        if is_consistent(x, n):
            if is_solution(x, n):
                output_solution(x)
            else:
                back_rec(x[:], n)
    x.pop()

def back_iter(n):
    x = [-1]
    while len(x) > 0:
        chosen = False
        while not chosen and x[-1] < 1:
            x[-1] += 1
            chosen = is_consistent(x, n)
        if chosen:
            if is_solution(x,n):
                output_solution(x)
            else:
                x.append(-1)
        else:
            x.pop()


print('BACKTRACK RECURSIV')
back_rec([], 2)
print('BACKTRACK ITERATIV')
back_iter(2)