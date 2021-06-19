def crosssieve(mv):
    cross = [False]*mv
    crossed = []

    for i in range(2, mv):
        if cross[i] == False:
            cross[i] == True
            crossed.append(i)

            for j in range(2*i, mv, i):
                if cross[j] == False:
                    crossed.append(j)

                cross[j] = True

    return crossed


N, K = map(int, input().split())

print(crosssieve(N+1)[K-1])
