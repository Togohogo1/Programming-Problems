from collections import defaultdict, deque


def bfs(a, flag):
    global path_len

    dist = [0 for i in range(10001)]
    queue = deque()
    vis = set()

    queue.append(a)
    vis.add(a)

    while queue:
        curr = queue.popleft()

        if curr == 0 and flag:
            path_len = dist[0]
            flag = False

        for i in graph[curr]:
            if i in vis:
                continue

            vis.add(i)
            queue.append(i)
            dist[i] = dist[curr] + 1

    return "Y" if len(vis) == N+1 else "N"


path_len = 0
graph = defaultdict(list)

N = int(input())

for i in range(N):
    link = list(map(int, input().split()))

    if link[0] == 0:
        graph[i+1].append(0)
    else:
        for j in link[1:]:
            graph[i+1].append(j)

print(bfs(1, True))
print(path_len)
