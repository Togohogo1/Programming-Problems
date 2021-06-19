from math import sqrt, floor

N = int(input())

n = ((sqrt(1+4*(2*N-2))) + 1) // (2)
a = (n*(n-1) // 2) + 1

print(int((n/2) * (2*a + n - 1)))
