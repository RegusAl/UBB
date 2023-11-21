import random
from random import choices, sample, randrange
from matplotlib.pyplot import bar, hist, grid, show, legend
from scipy.stats import binom

# EX 3
def ex3():
    bile_1 = 6
    bile_0 = 4

    # generare lista
    lista_generata = []
    for i in range(10000):
        suma = 0
        for j in range(5):
            choice = random.randint(0, 1)
            if choice == 1:
                suma += 1
            else:
                suma += 0
        lista_generata.append(suma)
    print(lista_generata)

    # afisare histograma
    distribution = dict([(i, 0) for i in range(6)])
    for i in range(6):
        distribution[i] = binom.pmf(i, 5, 6 / 10)

    bin_edges = [k + 0.5 for k in range(-1, 6)]

    hist(lista_generata, bin_edges, density=True, rwidth=0.9, color='green', edgecolor='black',
         alpha=0.5, label='frecvente relative')
    bar(distribution.keys(), distribution.values(), width=0.85, color='red', edgecolor='black',
        alpha=0.6, label='probabilitati')
    legend(loc='lower left')
    grid()
    show()

    contor = 0
    for i in lista_generata:
        if i > 2 and i <= 5:
            contor += 1

    print("P(2<x<=5): ", contor/10)

    result = binom.pmf(3,5,6/10) + binom.pmf(4,5,6/10) + binom.pmf(5,5,6/10)
    print("Valoarea teoretica: ", result)

