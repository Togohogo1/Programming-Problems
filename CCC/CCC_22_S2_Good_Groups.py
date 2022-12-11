import sys
from collections import defaultdict

input = sys.stdin.readline

d = defaultdict(str)
c1 = []
c2 = []
cnt = 0

X = int(input())

for i in range(X):
    a, b = map(str, input().split())
    c1.append((a, b))

Y = int(input())

for i in range(Y):
    a, b = map(str, input().split())
    c2.append((a, b))

G = int(input())

for i in range(G):
    a, b, c = map(str, input().split())
    d[a] = i
    d[b] = i
    d[c] = i

for a, b in c1:
    if d[a] != d[b]:
        cnt += 1

for a, b in c2:
    if d[a] == d[b]:
        cnt += 1

print(cnt)
