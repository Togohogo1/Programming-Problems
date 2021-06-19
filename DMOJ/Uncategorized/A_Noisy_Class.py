from collections import defaultdict
import sys

sys.setrecursionlimit(10001)
input = sys.stdin.readline


def hasCycle():
    for i in white:
        if dfs(i, white.copy(), grey, black):
            return "N"
    else:
        return "Y"


def move(v, source, dest):
    source.remove(v)
    dest.add(v)


def dfs(v, white, grey, black):
    move(v, white, grey)

    for i in graph[v]:
        if i in black:
            continue

        if i in grey:
            return True

        if dfs(i, white, grey, black):
            return True

    move(v, grey, black)
    return False


white = set()
grey = set()
black = set()

graph = defaultdict(set)

N = int(input())
M = int(input())

for i in range(M):
    r1, r2 = map(int, input().split())
    graph[r1].add(r2)
    white.add(r1)
    white.add(r2)

print(hasCycle())
