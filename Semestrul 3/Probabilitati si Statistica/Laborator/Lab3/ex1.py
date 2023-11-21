import random
from random import choices, sample, randrange
from math import comb, perm


# EX 1
def ex1():
    cazA = 0
    cazB = 0
    for i in range(10000):
        bile_rosii = 5
        bile_albastre = 3
        bile_verzi = 2

        alese_r = 0
        alese_a = 0
        alese_v = 0

        j = 0
        while j < 3:
            selected = random.randint(1, 3)
            if selected == 1:  # rosii
                if bile_rosii > 0:
                    bile_rosii -= 1
                    alese_r += 1
                else:
                    j -= 1
            elif selected == 2:  # albastre
                if bile_albastre > 0:
                    bile_albastre -= 1
                    alese_a += 1
                else:
                    j -= 1
            else:  # verzi
                if bile_verzi > 0:
                    bile_verzi -= 1
                    alese_v += 1
                else:
                    j -= 1
            j += 1

        A = alese_r > 1
        B = alese_r == 3 | alese_v == 3 | alese_a == 3

        if A & B:  # cazuri favorabile A intersectat cu B
            cazA += 1

        if A:  # cazuri favorabile A
            cazB += 1

    print("P(B|A) = ", cazA / cazB)

    pA = 1 - comb(10, 3) / comb(10, 5)
    pAB = comb(10, 3) / comb(10, 5)

    print("Valoarea teoretica a P(B|A) = ", pAB / pA)
