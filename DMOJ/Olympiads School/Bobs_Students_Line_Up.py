from itertools import accumulate as psa

m = 300001
arr = [0]

N = int(input())
S = input()

for i in S:
    arr.append(i == "R")

arr = list(psa(arr))

for i in range(1, N+1):
    left = i - 1 - (arr[i-1] - arr[0])
    right = (arr[N] - arr[i])
    m = min(m, left+right)

print(m)
