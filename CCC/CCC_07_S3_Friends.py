from collections import defaultdict, deque
import copy


def bfs(a, b):
    reached = False
    queue = deque()

    queue.append(a)
    temp_vis[a] = True

    while queue:
        temp = queue.popleft()

        if temp == b:
            reached = True

        for i in friends[temp]:
            if temp_vis[i]:
                continue

            temp_vis[i] = True
            queue.append(i)
            temp_dist[i] = temp_dist[temp] + 1

    return reached, temp_dist[b]


friends = defaultdict(list)
vis = defaultdict(bool)
dist = defaultdict(int)

n = int(input())

for i in range(n):
    x, y = map(int, input().split())
    vis[x], vis[y] = False, False
    dist[x], dist[y] = 0, 0
    friends[x].append(y)

while True:
    a, b = map(int, input().split())

    if (a, b) == (0, 0):
        break

    temp_vis = copy.deepcopy(vis)
    temp_dist = copy.deepcopy(dist)

    query = bfs(a, b)

    if query[0]:
        print("Yes", query[1]-1)
    else:
        print("No")
