vis = [0 for i in range(31)]


def ways(n):
    global vis

    if n in {0, 1}:
        return 1

    if vis[n] != 0:
        return vis[n]

    vis[n] = 4*ways(n-1) - ways(n-2)
    return 4*ways(n-1) - ways(n-2)


for i in range(5):
    N = int(input())

    if N % 2 == 0:
        print(ways(N//2+1) % 1000000)
    else:
        print(0)
