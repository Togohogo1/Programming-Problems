from math import sqrt
from collections import defaultdict
import sys
input = sys.stdin.readline

count = 0
j = 0

houses = []
rings = []
query = {}

N, Q = map(int, input().split())

for i in range(N):
    x, y = map(int, input().split())
    houses.append(x**2 + y**2)

houses.sort()
houses.append(-1)

for i in range(Q):
    rings.append(int(input())**2)

sorted_rings = sorted(rings)

for i in range(Q):
    if sorted_rings[i] >= houses[j]:
        while sorted_rings[i] >= houses[j]:
            if j >= N-1:
                j = N
                break
            else:
                j += 1

    query[sorted_rings[i]] = j

for i in rings:
    print(query[i])
