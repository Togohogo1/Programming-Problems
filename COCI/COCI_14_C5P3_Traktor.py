import sys
input = sys.stdin.readline

x = [0 for _ in range(100000)]
y = [0 for _ in range(100000)]
rd = [0 for _ in range(199999)]
ld = [0 for _ in range(199999)]

ans = -1
flag = True
N, K = map(int, input().split())

for i in range(N):
    xi, yi = map(int, input().split())
    x[xi] += 1
    y[yi] += 1
    rd[xi-yi-99999] += 1
    rd[(99999-xi)-yi-99999] += 1

    if (x[xi] == K or y[yi] == K or rd[xi-yi-99999] == K or rd[(99999-xi)-yi-99999] == K) and flag:
        ans = i + 1
        flag = False

print(ans)
