from backtracking.constants import VOWELS


def is_consistent(x):
    if len(x) != len(set(x)):
        return False
    return True


def is_consistent_b(x):
    if len(x) != len(set(x)):
        return False
    for i in range(1, len(x)):
        if (x[i] in VOWELS and x[i - 1] in VOWELS) or (x[i] not in VOWELS and x[i - 1] not in VOWELS):
            return False
    return True

def is_consistent_b_iter2(x, word):
    if len(x) != len(set(x)):
        return False
    for i in range(1, len(x)):
        if (word[x[i]] in VOWELS and word[x[i - 1]] in VOWELS) or (word[x[i]] not in VOWELS and word[x[i - 1]] not in VOWELS):
            return False
    return True

def is_solution(x, n):
    return len(x) == n


def output_solution(x):
    print(''.join(x))


def back_rec_anagrame1(x, cuv):
    x.append('-')
    for letter in cuv:
        x[-1] = letter
        # print('Candidate solution', x)
        if is_consistent_b(x):
            if is_solution(x, len(cuv)):
                output_solution(x)
            # will it work if we use it without else?
            else:
                back_rec_anagrame1(x[:], cuv)


def back_iter_anagrame1(cuv):
    x = [' ']
    sorted_word = [' '] + sorted(cuv)
    while len(x) > 0:
        chosen = False
        while not chosen and sorted_word.index(x[-1]) < len(cuv):
            x[-1] = sorted_word[sorted_word.index(x[-1]) + 1]
            chosen = is_consistent_b(x)
        if chosen:
            if is_solution(x, len(cuv)):
                output_solution(x)
            else:
                x.append(' ')
        else:
            x = x[:-1]


def output_solution_iter(x, word):
    actual_sol = [word[poz] for poz in x]
    print(''.join(actual_sol))


def back_iter_anagrame2(word):
    x = [-1]
    while len(x) > 0:
        chosen = False
        while not chosen and x[-1] < len(word)-1:
            x[-1] += 1
            chosen = is_consistent_b_iter2(x,word)
        # print(x)
        if chosen:
            if is_solution(x, len(word)):
                output_solution_iter(x, word)
            x.append(-1)
        else:
            x.pop()


word1 = 'alti'
print('Backtracking recursiv')
back_rec_anagrame1([], sorted(word1))
print('Backtracking iterativ V1')
back_iter_anagrame1(word1)
print('Backtracking iterativ V2')
back_iter_anagrame2(sorted(word1))
