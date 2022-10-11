# Calculați cel mai mare divizor comun a doua numere

a = int(input("A:"))
b = int(input("B:"))

def cmmdc(a, b):
    r = 0
    while a%b>0:
        r = a%b
        a = b
        b = r
    return b

print(cmmdc(a, b))