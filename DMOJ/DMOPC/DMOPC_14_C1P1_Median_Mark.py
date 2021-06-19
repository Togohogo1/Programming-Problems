import math
import statistics

c = []

for i in range(int(input())):
    c.append(int(input()))

print(math.ceil(statistics.median(c)))
