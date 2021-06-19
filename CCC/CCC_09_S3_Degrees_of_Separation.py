from collections import defaultdict, deque


def bfs(a, b):
    dist = [0 for i in range(100)]
    queue = deque()
    vis = set()

    queue.append(a)
    vis.add(a)

    while queue:
        curr = queue.popleft()

        if curr == b:
            return dist[b]

        for i in graph[curr]:
            if i in vis:
                continue

            vis.add(i)
            queue.append(i)
            dist[i] = dist[curr] + 1

    return "Not connected"


graph = defaultdict(set)
graph[1] = {6}
graph[2] = {6}
graph[3] = {4, 5, 6, 15}
graph[4] = {3, 5, 6}
graph[5] = {3, 4, 6}
graph[6] = {1, 2, 3, 4, 5, 7}
graph[7] = {6, 8}
graph[8] = {7, 9}
graph[9] = {8, 10, 12}
graph[10] = {9, 11}
graph[11] = {10, 12}
graph[12] = {9, 11, 13}
graph[13] = {12, 14, 15}
graph[14] = {13}
graph[15] = {3, 13}
graph[16] = {17, 18}
graph[17] = {18, 16}
graph[18] = {16, 17}

while True:
    op = input()

    if op == "i":
        x = int(input())
        y = int(input())

        graph[x].add(y)
        graph[y].add(x)

    if op == "d":
        x = int(input())
        y = int(input())

        graph[x].remove(y)
        graph[y].remove(x)

    if op == "n":
        x = int(input())

        print(len(graph[x]))

    if op == "f":
        ff = set()
        x = int(input())

        for i in graph[x]:
            for j in graph[i]:
                if j not in graph[x] and j != x:
                    ff.add(j)

        print(len(ff))

    if op == "s":
        x = int(input())
        y = int(input())

        print(bfs(x, y))

    if op == "q":
        break
