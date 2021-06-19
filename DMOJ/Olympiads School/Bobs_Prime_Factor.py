from math import sqrt


def max_pf(n):
    m = 2

    while n % 2 == 0:
        n //= 2

    for i in range(3, int(sqrt(n)) + 1, 2):
        while n % i == 0:
            m = max(m, i)
            n //= i

    if n > 2:
        m = max(m, n)

    return m


pf = -1
arr = []

for i in range(int(input())):
    a = int(input())
    arr.append(a)
    pf = max(pf, max_pf(a))

for i in arr:
    if i % pf == 0:
        print(i)
        break
