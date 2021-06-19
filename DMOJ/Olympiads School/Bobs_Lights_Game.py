from itertools import accumulate as psa

N, M = map(int, input().split())

c = 0
diff = [0]*(N+1)

for i in range(M):
    L, R = map(int, input().split())
    diff[L-1] += 1
    diff[R] -= 1

diff = list(psa(diff))

for i in range(N):
    c += (diff[i] % 2 == 1)

print(c)
