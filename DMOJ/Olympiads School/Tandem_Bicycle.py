import sys

count = 0

N, W = map(int, input().split())
weights = list(map(int, sys.stdin.readline().split()))

weights.sort()

L = 0
R = len(weights)-1

while L < R:
    if weights[L] + weights[R] <= W:
        count += R-L
        L += 1
    else:
        R -= 1

print(count)
