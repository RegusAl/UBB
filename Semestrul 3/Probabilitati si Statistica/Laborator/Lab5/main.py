from collections import Counter

import numpy as np
from matplotlib import pyplot as plt
from scipy.stats import uniform, expon
from matplotlib.pyplot import bar, show, hist, grid, legend, xticks , yticks, plot
from math import log

def condition(probabilitati, k, u):
    sum1 = 0
    for i in range(k):
        sum1 += probabilitati[i]

    sum2 = sum1 + probabilitati[k]

    if u <= sum2 and u > sum1:
        return 1
    return 0

def generate_random_numbers(grupe, probabliitati, n):
    u = uniform.rvs(size=n)

    random_numbers = []

    for i in range(n):
        for k in range(len(probabliitati)):
            if condition(probabliitati, k, u[i]) == 1:
                random_numbers.append(grupe[k])

    return random_numbers

def grupe_sanguine():
    grupe_sanguine = ['0', 'A', 'B', 'AB']
    probabilitati = [0.46, 0.40, 0.10, 0.04]
    n = 1000

    data = generate_random_numbers(grupe_sanguine, probabilitati, n)

    category_counts = {}
    for category in data:
        category_counts[category] = category_counts.get(category, 0) + 1

    freq = [category_counts.get(category, 0)/n for category in grupe_sanguine]
    print(freq)

    x_positions = np.arange(len(grupe_sanguine))

    plt.bar(x_positions, freq, width=0.3, color='red',
            alpha=0.5, label='Frecvente relative')

    plt.bar(x_positions + 0.3, probabilitati, width=0.3, color='blue', alpha=0.5, label='Probabilitati teoretice')

    plt.xticks(x_positions + 0.2, grupe_sanguine)
    plt.legend()
    plt.show()


def generate_random_numbers_2(n, a):
    u = uniform.rvs(size = n)
    numbers = -np.log(1 - u) / (a)
    return numbers

def imprimanta():
    alpha = 1/12
    data = generate_random_numbers_2(1000, alpha)
    hist(data, bins = 12, density = True, range = (0, 60))
    x = range(60)
    plot(x, expon.pdf(x, loc=0, scale =1/alpha), 'r-')
    xticks(range(0, 60, 5))
    grid()
    show()

    # simulari
    simulari = np.sum(data >= 5) / 1000;
    print("Simulari:  ", simulari)

    # probabilitate teoretica
    teoretica = 1 - expon.cdf(5, scale = 1/alpha)
    print("Teoretica: ", teoretica)


grupe_sanguine()
imprimanta()
