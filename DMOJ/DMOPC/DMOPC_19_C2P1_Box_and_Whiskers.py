import sys
import statistics

a = []
N = sys.stdin.readline()

# list(map(...)) does not work for some reason
b = map(int, sys.stdin.readline().split())
for i in b:
    a.append(i)

a.sort()

print(min(a), max(a), statistics.median(a[:len(a)//2]), statistics.median(a), statistics.median(a[len(a)-len(a)//2:]))
