import math

for i in range(int(input())):
    t = int(input())

    if t >= 34:
        print(0)
    else:
        print(math.factorial(t) % (2**32))
