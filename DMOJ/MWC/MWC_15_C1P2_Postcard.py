import sys
input = sys.stdin.readline


def cut(arr):
    for i in range(len(arr)):
        if "*" not in arr[0]:
            arr.remove(arr[0])
        else:
            break

    return arr[::-1]


def flip(arr):
    for i in arr:
        i = i[::-1]

    return list(map(list, zip(*arr)))[::-1]


grid = []
M, N = map(int, input().split())

for i in range(M):
    grid.append(list(input().split()))

grid = cut(cut(grid))
grid = list(map(list, zip(*grid[::-1])))
grid = flip(cut(cut(grid)))

for i in grid:
    print(" ".join(i))
