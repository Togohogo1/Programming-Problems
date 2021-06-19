from collections import defaultdict
import sys

input = sys.stdin.readline


class node:
    def __init__(self, let):
        self.elem = set()
        self.cont = set()
        self.let = let


def add(a, b):
    for i in b:
        a.add(i)

    return a


def dfs(node, path):
    path.append(node)

    for i in graph[node].cont:
        if i not in path:
            path = dfs(i, path)

    return path


def format(li):
    new = sorted(list(li.elem))
    return ",".join(new)


graph = defaultdict(int)

for i in range(int(input())):
    x1, f, x2 = map(str, input().split())

    if x1 not in graph:
        graph[x1] = node(x1)
    if x2 not in graph and x2.isupper():
        graph[x2] = node(x2)

    if x2.islower():
        graph[x1].elem.add(x2)
    if x2.isupper():
        graph[x1].cont.add(x2)

for i in graph:
    for j in graph[i].cont:
        for k in dfs(j, []):
            graph[i].elem = add(graph[i].elem, graph[k].elem)

for i in sorted(graph):
    print(f"{i} = {{{format(graph[i])}}}")
