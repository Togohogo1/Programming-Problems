import math
import sys

input = sys.stdin.readline

n = input()
length = len(n) - 2

t1 = 1
count = 0

# float() is somehow faster than int()
if float(n) >= 3628800:
    while True:
        count += 1

        # When n >= 10, the inverse of n! = len(n!)
        t1 = t1 + math.log(count, 10)

        if int(t1) > length:
            break

# The formula above does not hold true when n < 10
else:
    n = int(n)

    while True:
        count += 1
        n /= count

        if n == 1 or n == 0:
            break

print(count)
