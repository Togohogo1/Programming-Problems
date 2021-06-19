from collections import defaultdict
from math import sqrt


def takefact(num, n):
    count = 0

    while num != 0:
        count += num // n
        num //= n

    return count


def primefact(n):
    facts = defaultdict(int)

    while n % 2 == 0:
        facts[2] += 1
        n //= 2

    for i in range(3, int(sqrt(n))+1, 2):
        while n % i == 0:
            facts[i] += 1
            n //= i

    if n > 2:
        facts[n] += 1

    return facts


for i in range(10):
    temp_max = 0

    K, M = map(int, input().split())

    for fact_max in primefact(K):
        need = M*primefact(K)[fact_max]
        prod = fact_max * need

        lo, hi = 0, prod

        for i in range(21):
            mid = (hi + lo) // 2

            if takefact(mid, fact_max) < need:
                lo = mid
            elif takefact(mid, fact_max) > need:
                hi = mid
            else:
                break

        for i in range(mid, 0, -1):
            mid = i

            if takefact(i, fact_max) < need:
                mid = i + 1
                break

        temp_max = max(temp_max, mid)

    print(temp_max)
