from math import sqrt


def closestFact(n):
    for i in range(2, int(sqrt(n)+1)):
        if n % i == 0:
            return i, n//i

    return n, 1


curr = int(input())
cost = 0

while curr != 1:
    cf = closestFact(curr)
    curr -= cf[1]
    cost += cf[0] - 1

print(cost)
