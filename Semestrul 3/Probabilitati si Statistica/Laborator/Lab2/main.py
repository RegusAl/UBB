import random
from random import randint
from numpy.random import randint
from math import perm, comb, factorial
# from matplotlib.pyplot import  plt
import matplotlib.pyplot as plt
from matplotlib.pyplot import axis
from math import dist
import numpy as np

# help('random.randint')
# help('numpy.random.randint')

def dateNastere():
    lista_date_nastere = []
    for i in range(0, 23):
        lista_date_nastere.append(randint(1, 365))
    return lista_date_nastere


def existaDuplicate(lista_date):
    lista = set()
    lista_singure = lista.add
    lista_duplicate = set(el for el in lista_date if el in lista or lista_singure(el))
    return len(lista_duplicate) > 0


def simulare(number):
    cp = 0
    for i in range(0, number):
        lista = dateNastere()
        if (existaDuplicate(lista)):
            cp = cp + 1
    return cp / number


def aranjamente(n, k):
    return (factorial(n) / factorial(n - k))


def probabilitateGrup():
    aranj = aranjamente(365, 23)
    prod = 365 ** 23
    return (1-aranj/prod)

# print(dateNastere())
# print(existaDuplicate(dateNastere()))

print("Simulare")
print(simulare(10000))
print("Probabilitate")
print(probabilitateGrup())


def generarePuncte():
    # xpoint = np.array(random.sample(range(0,100), 100))
    # ypoint = np.array(random.sample(range(0,100), 100))

    # plt.scatter(x, y)
    plt.xlim(100)
    plt.ylim(100)
    # plt.close()
    # plt.plot(xpoint, ypoint, 'o')
    for i in range(0, 500):
        x = randint(0,101)
        y = randint(0, 101)
        plt.plot(x, y, 'o'+)
        # if(dist(x, y) < 50):
        #     plt.plot(x, y, 'o')
        # else:
        #     plt.plot(x, y, 'r')
    plt.show()

generarePuncte()








