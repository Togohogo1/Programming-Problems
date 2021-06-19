from collections import defaultdict

n = int(input())

graph = defaultdict(list)
dp = [0 for i in range(n+1)]

dp[1] = 1

while True:
    a, b = map(int, input().split())

    if (a, b) == (0, 0):
        break

    graph[a].append(b)

for i in range(1, n+1):
    for j in graph[i]:
        dp[j] += dp[i]

print(dp[n])
