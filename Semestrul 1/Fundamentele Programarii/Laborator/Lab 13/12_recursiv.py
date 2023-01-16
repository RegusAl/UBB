# Se dă o listă de numere întregi a1,...an. Determinaţi toate posibilităţile de a insera
# operatorul de + şi – între numere astfel încât rezultatul expresiei este pozitiv.
print("RECURSIV")
n = int(input("N = "))

l = []
for i in range (0,n):
    x = int(input("x = "))
    l.append(x)

dim = 2
suma = l[0]

def is_consistent(x, n, suma):
    if len(x) > n - 1:
         return False
    return True

def is_solution(x, n, suma):
    suma = l[0]
    if len(x) == n-1:
        for i in range (0, n-1):
            if x[i] == 0:
                suma = suma - l[i+1]
            else:
                suma = suma + l[i+1]
    if len(x) == n-1 and suma > 0:
            return True
    return False

def output_solution(x,n, suma):
    print("\n")
    print(l[0], end=" ")
    for i in range(0, n-1):
        if x[i] == 0:
            print('-', end=" ")
        else:
            print('+', end=" ")
        print(l[i+1], end=" ")

def backtracking_rec(x, dim, n, suma):
    x.append(-1)
    for i in range(0, dim):
        x[-1] = i
        if is_consistent(x, n, suma):
            if is_solution(x, n, suma):
                output_solution(x, n, suma)
            else:
                backtracking_rec(x[:], dim, n, suma)
    x.pop()

backtracking_rec([], 2, n, suma)