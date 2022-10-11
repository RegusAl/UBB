# Calculati suma a n numere naturale

n = int(input("n:"))

i = 1
suma = 0
while i<=n:
    x = int(input("X:"))
    suma = suma + x
    i = i + 1

print("Suma celor", n, "numere este", suma)
