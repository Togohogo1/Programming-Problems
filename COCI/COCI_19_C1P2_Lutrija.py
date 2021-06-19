import sys
from itertools import permutations as pm
from math import sqrt


def is_prime(n):
    if n < 2:
        return False

    for i in range(2, int(sqrt(n)+1)):
        if n % i == 0:
            return False

    return True


temp = []
valid = []

A, B = map(int, input().split())

# No need for A in valid
for i in [2, A-2, B-2, B, A+2, B+2]:
    if is_prime(i) and i not in valid:
        valid.append(i)

valid.sort()

# Loop through all permutations (A + perm(rest))
for i in range(len(valid)):
    for j in pm(valid, i+1):
        temp = [A]

        for k in range(len(j)):
            # if diff is prime
            # j[k] = 19, temp = [2] -> temp = [2, 19]
            if is_prime(abs(j[k]-temp[k])):
                temp.append(j[k])
            else:
                break

        # End program on first occurrence of B
        if temp[-1] == B:
            print(len(temp))
            print(*temp)
            sys.exit()

print(-1)
