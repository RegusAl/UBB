import numpy as np
from tabulate import tabulate


def partition_equal_subset_sum(arr):
    total_sum = np.array(arr).sum()
    if total_sum % 2 != 0:
        return False

    sum_to_check = total_sum // 2
    dp = np.zeros(shape=(len(arr) + 1, sum_to_check + 1))
    dp[:, 0] = 1
    dp[0, 1:] = 0

    for crt_sum in range(1, sum_to_check + 1):
        for index in range(1, len(arr) + 1):
            dp[index][crt_sum] = dp[index - 1][crt_sum]
            if crt_sum >= arr[index - 1]:
                if dp[index - 1][crt_sum - arr[index - 1]] == 1:
                    dp[index][crt_sum] = 1

    return dp


def get_equal_sum_subsets(arr, s, dp):
    k = len(arr)
    if not dp[k][s]:
        return [], []
    index = k
    crt_sum = s
    set1 = []
    set2 = []
    while index > 0 and crt_sum >= 0:
        if dp[index - 1][crt_sum]:
            index -= 1
            set2.append(arr[index])
        else:
            if dp[index - 1][crt_sum - arr[index - 1]]:
                index -= 1
                crt_sum -= arr[index]
                set1.append(arr[index])
    return set1, set2


l1 = [3, 1, 1, 2, 2, 1]
array_sum = sum(l1) // 2
dp = partition_equal_subset_sum(l1)
print('Dynamic programming structure that was built is:')
print(tabulate(dp, showindex="always", headers=['Sum=' + str(i) for i in range(array_sum + 1)], tablefmt="grid",
               numalign="center"))
print(get_equal_sum_subsets(l1, array_sum, dp))
