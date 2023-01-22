import math


def max_expression(arr):
    if len(arr) < 4:
        print("Array-ul nu are suficiente elemente.")
        return

    number_of_elements = len(arr)
    dp1 = [-math.inf] * (number_of_elements + 1)
    dp2 = [-math.inf] * number_of_elements
    dp3 = [-math.inf] * (number_of_elements - 1)
    dp4 = [-math.inf] * (number_of_elements - 2)

    for i in range(len(arr) - 1, -1, -1):
        dp1[i] = max(dp1[i + 1], arr[i])

    dp2[-1] = -math.inf
    dp2[-2] = arr[-1] - arr[-2]
    for i in range(len(arr) - 2, -1, -1):
        dp2[i] = max(dp2[i + 1], dp1[i + 1] - arr[i])

    for i in range(len(arr) - 3, -1, -1):
        dp3[i] = max(dp3[i + 1], dp2[i + 1] + arr[i])

    for i in range(len(arr) - 4, -1, -1):
        dp4[i] = max(dp4[i + 1], dp3[i + 1] - arr[i])

    return dp1, dp2, dp3, dp4


def get_indices(dp1, dp2, dp3, dp4):
    max_value = dp4[0]
    q = 0
    while dp4[q] == max_value:
        q += 1

    value2 = max_value + arr[q - 1]
    p = q
    while dp3[p] == value2:
        p += 1

    value3 = value2 - arr[p - 1]
    n = p
    while dp2[n] == value3:
        n += 1

    value4 = value3 + arr[n - 1]
    m = n
    while dp1[m] == value4:
        m += 1

    return m, n, p, q, max_value


def print_solution(m, n, p, q, max_value):
    print('Indicii cautati:', q - 1, p - 1, n - 1, m - 1)
    print('Valoarea maxima:', max_value)
    s = "A[{m}] - A[{n}] + A[{p}] - A[{q}] = {Am} - {An} + {Ap} - {Aq} = {maxvalue}"
    s = s.format(m=m - 1, n=n - 1, p=p - 1, q=q - 1, Am=arr[m - 1], An=arr[n - 1],
                 Ap=arr[p - 1],
                 Aq=arr[q - 1], maxvalue=max_value)
    print(s)


arr = [30, 5, 15, 18, 30, 40]
dp1, dp2, dp3, dp4 = max_expression(arr)
m, n, p, q, max_value = get_indices(dp1, dp2, dp3, dp4)
print_solution(m, n, p, q, max_value)
