from math import ceil, sqrt


def fact(n):
    facts = []

    for i in range(1, int(sqrt(n))+1):
        if n % i == 0:
            facts.append((i, n//i))

    return facts


def nasty(facts):
    for i in facts:
        for j in facts:
            if abs(i[0] - i[1]) == sum(j) or abs(j[0] - j[1]) == sum(i):
                return True

    return False


for i in range(int(input())):
    num = int(input())

    if nasty(fact(num)):
        print(f"{num} is nasty")
    else:
        print(f"{num} is not nasty")
