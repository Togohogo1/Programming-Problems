from collections import defaultdict, deque
import sys

input = sys.stdin.readline


def bfs(a):
    queue = deque()
    vis = [False for i in range(N+1)]
    dist = [0 for i in range(N+1)]

    queue.append(a)
    vis[a] = True

    while queue:
        curr = queue.popleft()

        for i in graph[curr]:
            if vis[i]:
                continue

            vis[i] = True
            queue.append(i)
            dist[i] = dist[curr] + 1

    return dist


N, M, T = map(int, input().split())

graph = defaultdict(list)
query = [-1]

for i in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)

for i in range(1, N+1):
    query.append(bfs(i))

for i in range(int(input())):
    qa, qb = map(int, input().split())

    if query[qa][qb] == 0:
        print("Not enough hallways!")
    else:
        print(query[qa][qb]*T)
