import copy
import random


def partition(lst, l, r):
    pivot = lst[r]
    i = l - 1
    for j in range(l, r):
        if lst[j] < pivot:
            i += 1
            lst[i], lst[j] = lst[j], lst[i]

    lst[i + 1], lst[r] = lst[r], lst[i + 1]
    return i + 1


def kth_smallest_number(lst, l, r, k):
    if l == r:
        return lst[l]
    pos = partition(lst, l, r)

    i = pos - l + 1

    if i == k:
        return lst[pos]

    elif i > k:
        return kth_smallest_number(lst, l, pos - 1, k)
    else:
        return kth_smallest_number(lst, pos + 1, r, k - i)


def test_kth_smallest_elem():
    my_list = [5, 4, 9, 1, 2, 10, 11, 6]
    sorted_list = copy.deepcopy(my_list)
    sorted_list.sort()

    for i in range(30):
        random.shuffle(my_list)
        # print(my_list)
        k = random.randint(1, len(my_list))
        smallest = kth_smallest_number(my_list, 0, len(my_list) - 1, k)
        assert (smallest == sorted_list[k - 1])
