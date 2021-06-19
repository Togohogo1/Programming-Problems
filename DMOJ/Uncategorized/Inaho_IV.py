import math

not_very_final = 0

N = int(input())

a = list(map(float, input().split()))
b = list(map(float, input().split()))

for i in range(N):
    not_very_final += (a[i] - b[i]) ** 2

print(math.sqrt(not_very_final))
