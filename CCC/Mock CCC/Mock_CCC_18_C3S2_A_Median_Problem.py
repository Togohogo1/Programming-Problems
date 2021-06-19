import math
import statistics

c = []

for i in range(int(input())):
    b = list(map(int, input().split()))
    c.append(statistics.median(b))

print(math.ceil(statistics.median(c)))
