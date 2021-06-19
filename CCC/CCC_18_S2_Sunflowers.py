a = []
d = []
t1 = []

N = int(input())

for i in range(N):
    a = list(map(int, input().split(" ")))
    d.append(a)


def corners():
    for i in range(4):
        for i in range(N):
            for j in range(N-1):
                if i > j:
                    temp = d[i][j]
                    d[i][j] = d[j][i]
                    d[j][i] = temp

        for i in range(N):
            d[i].reverse()

        t1.append(d[0][0])


def listrotate():
    corners()

    for i in range(4):
        for i in range(N):
            for j in range(N-1):
                if i > j:
                    temp = d[i][j]
                    d[i][j] = d[j][i]
                    d[j][i] = temp

        for i in range(N):
            d[i].reverse()

        if min(t1) == d[0][0]:
            prettyprint()
            break


def prettyprint():
    for i in range(N):
        print()

        for j in range(N):
            print(d[i][j], end=" ")


listrotate()
