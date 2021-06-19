from math import sqrt

c = 0
factors = []

N = int(input())

for i in range(1, int(sqrt(N)+1)):
    if N % i == 0:
        factors.append([i, N//i])
        factors.append([N//i, i])

for i in factors:
    x = (i[0]+i[1]) / 2
    y = (i[0]-i[1]) / 2

    if x > 0 and y > 0:
        if x % 1 == 0 and y % 1 == 0:
            c += 1

print(c)
