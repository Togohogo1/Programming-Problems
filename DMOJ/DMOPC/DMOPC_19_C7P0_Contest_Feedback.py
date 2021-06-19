from itertools import combinations
from statistics import mean

A, B, C, D = map(int, input().split())

for i in range(2, 5):
    for j in combinations([A, B, C, D], i):
        print(mean(j))
