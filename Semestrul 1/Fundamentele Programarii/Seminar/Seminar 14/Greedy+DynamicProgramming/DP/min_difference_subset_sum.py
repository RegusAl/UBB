def min_difference_subsets(arr, n):
    arr_sum = sum(arr)
    half_sum = arr_sum // 2 + 1

    dp = [False for i in range(half_sum)]
    dp_aux = [False for i in range(half_sum)]

    dp[0] = True
    for arr_index in range(n):
        for suma_crt in range(half_sum):
            if suma_crt + arr[arr_index] < half_sum and dp[suma_crt]:
                dp_aux[suma_crt + arr[arr_index]] = True

        for suma_crt in range(half_sum):
            if dp_aux[suma_crt]:
                dp[suma_crt] = dp_aux[suma_crt]
            dp_aux[suma_crt] = False

    for suma_crt in range(half_sum - 1, 0, -1):
        if dp[suma_crt]:
            return arr_sum - 2 * suma_crt

    return 0


def test_min_difference_subset_sum():
    arr = [1, 6, 11, 5]
    n = len(arr)
    assert (min_difference_subsets(arr, n) == 1)

    arr = [1, 2, 3, 4]
    n = len(arr)
    assert (min_difference_subsets(arr, n) == 0)

    arr = [10, 18, 12, 11]
    n = len(arr)
    assert (min_difference_subsets(arr, n) == 5)
