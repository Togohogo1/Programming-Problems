n, m = map(int, input().split())

gridlist = []

for i in range(n):
    row = list(input())
    gridlist.append(row)


def grid(li):
    for i in range(n):
        for j in range(m):
            try:
                if li[i][j] == "o":
                    if li[i+1][j] == ".":
                        li[i+1][j] = "o"
                        li[i][j] = "."
            except IndexError:
                pass

    return li


for i in range(100):
    grid(gridlist)

for i in grid(gridlist):
    for j in i:
        print(j, end="")

    print("")
