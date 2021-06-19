from collections import defaultdict, deque
import sys

sys.setrecursionlimit(100001)
input = sys.stdin.readline


def find(node, path):
    path.add(node)

    for i in graph[node]:
        if i not in path:
            path = find(i, path)
            order.append(i)

    return path


def delete(order, graph):
    for i in order:
        if len(graph[i]) == 1:
            link = next(iter(graph[i]))

            if i not in pho:
                graph.pop(i)
                graph[link].remove(i)


def longest(n, node):
    q = deque()
    vis = [False for i in range(n)]
    dist = [0 for i in range(n)]

    q.append(node)
    vis[node] = True

    while q:
        t = q.popleft()

        for i in graph[t]:
            if vis[i]:
                continue

            vis[i] = True
            q.append(i)
            dist[i] = dist[t] + 1

    return max(dist), dist.index(max(dist))


N, M = map(int, input().split())
pho = set(map(int, input().split()))

p = next(iter(pho))
order = []
graph = defaultdict(set)

for i in range(N-1):
    r1, r2 = map(int, input().split())
    graph[r1].add(r2)
    graph[r2].add(r1)

find(p, set())
delete(order, graph)
furthest = longest(N, p)[1]

print(2*(len(graph)-1) - longest(N, furthest)[0])
