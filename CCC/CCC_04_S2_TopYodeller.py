n, k = map(int, input().split())

m = -1001
yod = [0]*n
ranks = [[0, 0, 0] for i in range(n)]

for i in range(k):
    scores = list(map(int, input().split()))

    for i in range(n):
        yod[i] += scores[i]

    temp = list(sorted(yod.copy(), reverse=True))

    for i in range(n):
        ranks[i][0] = yod[i]
        ranks[i][1] = temp.index(yod[i]) + 1
        ranks[i][2] = max(ranks[i][2], ranks[i][1])

for i in range(n):
    m = max(m, ranks[i][0])

for i in range(n):
    if ranks[i][0] == m:
        print(f"Yodeller {i+1} is the TopYodeller: score {ranks[i][0]}, worst rank {ranks[i][2]}")
