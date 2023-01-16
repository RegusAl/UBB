def is_consistent(x):
    if len(x) == 1:
        return True
    for i in range(len(x)):
        for j in range(i + 1, len(x)):
            if x[i] >= x[j]:
                return False
    return True


def is_solution(x):
    return len(x) > 1


def backtrack_rec_subsecv(x, k, lista):
    if k == len(lista):
        return
    else:
        x.append(-1)
        # print('Sol',x)
        s_k = lista[k:]
        for value in s_k:
            x[-1] = value
            if is_consistent(x):
                if is_solution(x):
                    print(x)
                backtrack_rec_subsecv(x[:], k + 1, lista)


def is_consistent_iter(x, lista):
    # print('Sol', x, end=' ')
    # output_solution_iter(x, lista)
    if len(x) == 1:
        return True
    if len(x) > len(lista):
        return False
    if len(x) != len(set(x)):
        return False
    if x != sorted(x):
        return False

    for i in range(1,len(x)):
        if lista[x[i]]<=lista[x[i-1]]:
            return False
    actual_sol = [lista[poz] for poz in x]
    # print('Actual sol', actual_sol)

    # for i in range(1, len(actual_sol)):
    #     if actual_sol[i] <= actual_sol[i-1]:
    #         return False
    return True


def is_solution_iter(x):
    return len(x) >= 2


def output_solution_iter(x, lista):
    solution = [lista[i] for i in x]
    print(solution)


def backtrack_iter_subsecv(lista):
    x = [-1]
    while len(x) > 0:
        chosen = False
        while not chosen and x[-1] < len(lista) - 1:
            x[-1] += 1
            chosen = is_consistent_iter(x, lista)
        if chosen == True:
            if is_solution_iter(x):
                output_solution_iter(x, lista)
            x.append(-1)
        else:
            x.pop()


l = [1, 2, 4, 2, 1, 3, 9]
backtrack_rec_subsecv([], 0, l)
print('-------------------')
backtrack_iter_subsecv(l)
