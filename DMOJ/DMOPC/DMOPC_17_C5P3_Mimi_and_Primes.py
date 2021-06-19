import sys
from math import sqrt

input = sys.stdin.readline

def GCD(a, b):
    if b == 0:
        return a

    return GCD(b, a%b)


N = int(input())
nums = list(map(int, input().split()))

g = m = 0

for i in nums:
    g = GCD(g, i)

while g % 2 == 0:
    m = max(2, m)
    g //= 2

for i in range(3, int(sqrt(g))+1, 2):
    while g % i == 0:
        m = max(m, i)
        g //= i

if g > 2:
    m = max(m, g)

if m < 2:
    print("DNE")
else:
    print(m)

