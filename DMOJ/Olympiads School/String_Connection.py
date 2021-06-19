from functools import cmp_to_key


def cmp(a, b):
    if a > b:
        return -1
    else:
        return 1


d = []
f = list(map(int, input().split(" ")))

for i in range(f[0]):
    d.append(input())

# Using your own method (cmp) to compare vaules of a list
d.sort(key=cmp_to_key(cmp))

for i in d:
    print(i, end="")
