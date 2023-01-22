import math


def max_subarray_sum(arr):
    maximums = [-math.inf] * len(arr)
    overall_max = -math.inf
    end_max_subarray = -1

    for pos in range(len(arr)):
        max_ending_at_crt_pos = max(maximums[pos - 1] + arr[pos], arr[pos])
        maximums[pos] = max_ending_at_crt_pos

        if max_ending_at_crt_pos > overall_max:
            overall_max = max_ending_at_crt_pos
            end_max_subarray = pos

    print('Maximum sum of subarray ending at each index', maximums)

    value = overall_max
    start_max_subarray = end_max_subarray
    while value > 0:
        value -= arr[start_max_subarray]
        start_max_subarray -= 1
    return overall_max, arr[start_max_subarray + 1:end_max_subarray + 1]


def test_max_subarray_sum():
    max_sum, max_subarray = max_subarray_sum([-2, -1, -3, 4, -1, 2, 1, -5, 4])
    assert (max_sum == 6)
    assert (max_subarray == [4, -1, 2, 1])

    max_sum, max_subarray = max_subarray_sum([-3, -4, 5, -1, 2, -4, 6, -1])
    assert (max_sum == 8)
    assert (max_subarray == [5, -1, 2, -4, 6])
