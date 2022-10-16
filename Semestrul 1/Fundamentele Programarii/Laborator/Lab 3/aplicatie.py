# 8, 16

'''
1. Citirea unei liste de numere intregi
2,3. Gasirea secventelor de lungime maxima care respectă o proprietatea dată. Fiecare student primeste 2 proprietati din lista
de mai jos.
4. Iesire din aplicatie.
Documentatia să contină:
Scenarii de rulare pentru cele două cerinte primite (vezi curs 1 – scenarii de rulare)
Cazuri de testare pentru cele doua cerinte în format tabelar (vezi curs 1 – cazuri de testare)
'''

# functia ce afiseaza meniul
def print_menu():
    print("1. Citeste de la tastatura o lista de numere intregi.")
    print("2. Gaseste secventa de lungime maxima ce are toate elementele in intervalul [0, 10].")
    print("3. Gaseste secventa de numere, a caror scriere in baza 10 foloseste aceleasi cifre.")
    print("4. Iesire din aplicatie.")

# citirea  listei de numere
def read_list():
    numbers_list = []
    n = int(input("Numarul de elemente ale listei:"))
    for i in range(n):
        number = int(input("Introduceti numar:"))
        numbers_list.append(number)
    return numbers_list

# gasirea secventelor de lungime maxima ce respecta proprietatea ca toate elementele sa fie in intervalul [0, 10]
def max_interval(list):
    aux_list = []
    max_list = aux_list.copy()
    max = 0
    nr = 0
    for i in list:
        if i <= 10 and i >= 0:
            nr += 1
            aux_list.append(i)
        elif nr>max:
            max = nr
            nr = 0
            max_list = aux_list.copy()
            aux_list = []
        else:
            nr = 0
            aux_list = []
    if nr>max:
        max = nr
        nr = 0
        max_list = aux_list.copy()
        aux_list = []
    return max_list

# gasirea seventelor de lungime maxima a caror scriere in baza 10 foloseste aceleasi cifre

# functia creeaza numere noi in care cifrele sunt in ordine crescatoare
def new_number(number):
    aux = 0
    f = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    while number!=0:
        f[int(number%10)] += 1
        number /= 10
    number = 0
    i = 1
    while i < 10:
        if f[i] != 0:
            number = number * 10 + i
        i += 1
    return number

# functia compara numerele doua cate doua pentru a afla secventa maxima
def base10(list):
    aux_list = []
    max_list = []
    # lista in care sunt numerele cu cifrele in ordine crescatoare
    for el in list:
        aux_list.append(new_number(el))
    startMax = 0
    lungMax = 0
    startCrt = 0
    lungCrt = 1
    i = 1
    while i<len(list):
        if aux_list[i] == aux_list[i-1]:
            lungCrt += 1
        else:
            if lungCrt > lungMax:
                startMax = startCrt
                lungMax = lungCrt
            startCrt = i
            lungCrt = 1
        i += 1
    return list[startMax:startMax+lungMax]

# MENIUL PRINCIPAL
def start():
    global_list = []
    while True:
        print_menu()
        option = int(input("Optiunea este:"))
        # 1. 
        if option == 1:
            global_list = read_list()
            print("Lista de numere intregi este", global_list)
        # 2.
        if option == 2:
            print(max_interval(global_list))
        # 3. 
        if option == 3:
            print(base10(global_list))
        # 4.
        if option == 4:
            print("Ai iesit din aplicatie!")
            return

start()