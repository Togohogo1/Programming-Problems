H = int(input())
T = int(input())
tractors = list(map(int, input().split()))
M = int(input())
farm = input()

tractors.sort()

m = 1
c = 0

for i in range(M):
    if farm[i] != "1":
        c += 1
    else:
        m = max(m, c)
        c = 0

for i in tractors[::-1]:
    if i <= m:
        break

print(-(-H//i))
