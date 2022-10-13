'''
Găsește cel mai mic număr m din șirul lui Fibonacci definit de
f[0]=f[1]=1, f[n]=f[n-1]+f[n-2], pentru n>2,
mai mare decât numărul natural n dat, deci exista k astfel ca f[k]=m si m>n.
'''

# functie ce arata toate cele n numere fibonacci
def fibonacci(n):
    a = 1
    b = 1
    c = a+b
    #print(a)
    #print(b)
    i = 2
    while c<=n:
        c = a+b
        a = b
        b = c
        #print(c)
        i = i+1
    print("Cel mai mic numar m din sirul lui Fibonacci mai mare de", n, "este", c)

n = input("n:")
fibonacci(int(n))