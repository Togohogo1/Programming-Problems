from collections import Counter


def mode_function2(lst):
    lst.sort()
    counter = Counter(lst)
    _, val = counter.most_common(1)[0]

    return [x for x, y in counter.items() if y == val]


N = int(input())
li = list(map(int, input().split()))

for i in mode_function2(li):
    print(i, end=" ")
