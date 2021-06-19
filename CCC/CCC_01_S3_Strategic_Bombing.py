from collections import defaultdict, deque
from copy import deepcopy


def bfs(a, b):
    queue = deque()
    vis = set()

    queue.append(a)
    vis.add(a)

    while queue:
        curr = queue.popleft()

        if curr == b:
            return False

        for i in temp[curr]:
            if i in vis:
                continue

            vis.add(i)
            queue.append(i)

    return True


c = 0
roads = []
graph = defaultdict(set)

while True:
    road = input()

    if road == "**":
        break

    a = road[0]
    b = road[1]

    roads.append([a, b])

    graph[a].add(b)
    graph[b].add(a)

for a, b in roads:
    temp = deepcopy(graph)

    temp[a].remove(b)
    temp[b].remove(a)

    if bfs("A", "B"):
        print(a+b)
        c += 1

print(f"There are {c} disconnecting roads.")
