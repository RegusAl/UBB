import random
from random import sample
from math import factorial, perm, comb
from itertools import permutations, combinations

## 2

# a)
print(list(permutations("WORD")))

# b)

print(len(list(permutations("WORD"))))
print(factorial(len("WORD")))

# c)
print(random.choice(list(permutations("WORD"))))

## 3

def aranjamente(word, number, numar_total=False, aleator=False):
    if numar_total is False and aleator is False:
        print(list(permutations("WORD", number)))
    elif numar_total is True:
        # numar = factorial(len(word)) / factorial(len(word) - number)
        print(perm(len(word), number))
    elif aleator is True:
        print(sample(list(permutations("WORD", number)), 1))

aranjamente("WORD", 2)
aranjamente("WORD", 2, numar_total=True)
aranjamente("WORD", 2, aleator=True)

def combinari(word, number, numar_total=False, aleator=False):
    if numar_total is False and aleator is False:
        print(list(combinations(word, number)))
    elif numar_total is True:
        print(comb(len(word), number))
    elif aleator is True:
        print(sample(list(combinations(word, number)), 1))


combinari("WORD", 2)
combinari("WORD", 2, numar_total=True)
combinari("WORD", 2, aleator=True)
