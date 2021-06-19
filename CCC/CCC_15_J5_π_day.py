def find(pie, ppl, m):
    if visited[pie][ppl][m] == 0:
        if pie == ppl:
            visited[pie][ppl][m] = 1
        elif ppl == 1:
            visited[pie][ppl][m] = 1
        else:
            temp = 0

            for i in range(m, (pie//ppl)+1):
                temp += find(pie-i, ppl-1, i)

            visited[pie][ppl][m] = temp

    return visited[pie][ppl][m]


n = int(input())
k = int(input())

visited = [[[0 for x in range(n+1)] for y in range(k+1)] for z in range(n+1)]

print(find(n, k, 1))
