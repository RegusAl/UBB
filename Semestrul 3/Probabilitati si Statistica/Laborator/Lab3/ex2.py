import random
from random import choices, sample, randrange
from matplotlib.pyplot import bar, hist, grid, show, legend


# EX 2
def ex2():
    data = [randrange(0, 7) for _ in range(500)]
    bin_edges = [k + 0.5 for k in range(0, 7)]
    hist(data, bin_edges, density=True, rwidth=0.9, color='green', edgecolor='black',
         alpha=0.5, label='frecvente relative')
    distribution = dict([(i, 1 / 6) for i in range(1, 7)])
    bar(distribution.keys(), distribution.values(), width=0.85, color='red', edgecolor='black',
        alpha=0.6, label='probabilitati')
    legend(loc='lower left')
    grid()
    show()
