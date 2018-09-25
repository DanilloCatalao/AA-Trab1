import time
import random

class InputError(Exception):
    pass

def merge(_list1, _list2):
    i = 0
    j = 0
    result = []
    while i < len(_list1) and j < len(_list2):
        if _list1[i] < _list2[j]:
            result.append(_list1[i])
            i += 1
        else:
            result.append(_list2[j])
            j += 1

    if i < len(_list1):
        remainder = _list1[i:]
    else:
        remainder = _list2[j:]

    for element in remainder:
        result.append(element)

    return result

def merge_sort(_list):
    if len(_list) == 1:
        return _list

    partition_1 = _list[:len(_list)/2]
    partition_2 = _list[len(_list)/2:]

    partition_1 = merge_sort(partition_1)
    partition_2 = merge_sort(partition_2)
    result = merge(partition_1, partition_2)

    return result

def linear_selection(_list, k):
    if k < 0 or k > len(_list):
        raise InputError()

    group_length = 5
    if len(_list) <= group_length:
        _list = merge_sort(_list)
        k -= 1
        return _list[k]

    group_count = len(_list) / group_length
    if len(_list) % group_length != 0:
        group_count += 1

    median_list = []

    for i in xrange(group_count):
        start = i * group_length
        group = _list[start: start + group_length]
        group = merge_sort(group)
        median = group[len(group)/2]
        median_list.append(median)

    median = linear_selection(median_list, len(median_list) / 2)
    below_median = []
    above_median = []
    for element in _list:
        if element < median:
            below_median.append(element)
        else:
            above_median.append(element)

    if len(below_median) == k - 1:
        return median
    elif len(below_median) > k - 1:
        return linear_selection(below_median, k)
    else:
        return linear_selection(above_median, k - len(below_median) - 1)

def sort_selection(_list, k):
    _list = merge_sort(_list)
    k -= 1

    return _list[k]

max_int = 100000

def random_list(size):
    _list = []
    for _ in xrange(size):
        _list.append(random.randint(1, max_int))

    return _list

def main():
    f = open("relatorio.txt", "w")
    for n in xrange(1000, 11000, 1000):
        k = n / 2
        linear_average = 0
        sort_average = 0
        for _ in xrange(10):
            _list = random_list(n)
            start = time.time()
            linear_selection(_list, k)
            end = time.time()
            linear_average += (end - start)
            start = time.time()
            sort_selection(_list, k)
            end = time.time()
            sort_average += (end - start)
        linear_average /= 10
        sort_average /= 10
        f.write("n = {}\n".format(n))
        f.write("linear: {}\n".format(linear_average))
        f.write("sort: {}\n".format(sort_average))
    f.close()

if __name__ == "__main__":
    main()

