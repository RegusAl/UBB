import numpy
from scipy.stats import norm, expon, uniform
from numpy import mean, std, linspace, random, where
from matplotlib.pyplot import show, hist, grid, legend, xticks, plot, figure, bar

# Problema 1

print("\nProblema 1) \n")

# a)
simulari = 5000
X = random.normal(165, 10, simulari)

# b)
figure()
hist(X, bins=16, density=True, range=(130, 210), alpha=1, color='blue', edgecolor='black')

minim = min(X)
maxim = max(X)

range = linspace(minim, maxim, simulari)
density_values = norm.pdf(range, minim, maxim)

plot(range, density_values, 'r')


# ii)
val_medie = mean(X)
print("Valoarea medie: ", val_medie)
valori_interval = sum((X >= 160) & (X <= 170))
print("Deviatia standard: ", std(X))
print("Proportia de valori: ", valori_interval / simulari)

show()

# Problema 2

print("\nProblema 2) \n")

N = 5000  # numarul de simulari
r = random.rand(1, N)
exp = expon(scale=5).rvs(size=N)
unif = uniform(4, 2).rvs(size=N)

y = where(r <= 0.5, exp, unif)

# a)
media = mean(y)
deviatia = std(y)
print("Media:", media)
print("Deviatia standard:", deviatia)

# b)
probabilitatea = mean(y < 5)
print("Probabilitatea mai mica de 5 secunde:", probabilitatea)


# Problema 3
print("\nProblema 3) \n")

from numpy import exp, mean, random


# e^(-x^2)
def functie_exp(x):
    return exp(-x ** 2)


def monte_carlo(a, b, val):
    #  random = [a,b]
    random_samples = random.uniform(a, b, val)
    function_values = functie_exp(random_samples)
    # Estimare
    estimare = mean(function_values) * (b - a)
    return estimare


result = monte_carlo(-1, 3, 1000)

print(f"Valoare estimata: {result}")
