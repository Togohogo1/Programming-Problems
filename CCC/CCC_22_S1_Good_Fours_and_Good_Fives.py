import sys
input = sys.stdin.readline

N = int(input())
cnt = 0

for i in range(N):
    y = (N-4*i) / 5

    if y < 0:
        break

    if y % 1 == 0:
        cnt += 1

print(cnt)
