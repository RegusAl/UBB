from random import sample

from scipy.stats import hypergeom, geom


def ex2():
    print("EX2")
    lista = []
    for i in range(500):
        total = 0
        bilet_castigator = False

        while not bilet_castigator:
            alese = sample(range(1, 50), 6)
            castigatoare = sample(range(1, 50), 6)

            corecte = 0

            for bila in alese:
                if bila in castigatoare:
                    corecte += 1

            if corecte >= 3:
                bilet_castigator = True

            total += 1

        lista.append(total - 1)

    print("Lista cu numarul de bilete necastigatoare pana la primul bilet necastigator: \n", lista)

    areLoc = 0
    for nr in lista:
        if nr >= 10:
            areLoc += 1

    probabilitateSimulata = areLoc / 500
    print("Probabilitatea simulata: \n" + str(probabilitateSimulata))

    p = sum(hypergeom.pmf(k, 49, 6, 6) for k in range(3, 7))
    probabilitateTeoretica = 1 - geom.cdf(9, p)
    print("Probabilitatea teoretica: \n", probabilitateTeoretica)
