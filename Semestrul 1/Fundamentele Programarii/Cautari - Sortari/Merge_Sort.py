def merge(arr1, arr2):
    result = []
    i = 0
    j = 0

    while i < len(arr1) and j < len(arr2):
        if arr1[i] < arr2[j]:
            result.append(arr1[i])
            i += 1
        else:
            result.append(arr2[j])
            j += 1

    while i < len(arr1):
        result.append(arr1[i])
        i += 1

    while j < len(arr2):
        result.append(arr2[j])
        j += 1

    return result

def merge_sort(l):
    if len(l) <= 1:
        return l

    middle = len(l) // 2

    left = l[:middle]
    right = l[middle:]

    sorted_left = merge_sort(left)
    sorted_right = merge_sort(right)

    return merge(sorted_left, sorted_right)

l = [23, 44, 12, 10, 8, 45, 9, 2, 3]
assert (merge_sort(l)) == [2, 3, 8, 9, 10, 12, 23, 44, 45]
