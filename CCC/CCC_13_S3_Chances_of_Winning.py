count = 0

combs = [[1, 2], [1, 3], [1, 4], [2, 3], [2, 4], [3, 4]]
scores = [[0, 3], [3, 0], [1, 1]]
score = [0]*4


def find(scores, temp, m):
    global count

    if (len(temp) == m):
        tempScore = score.copy()

        for i in range(m):
            if temp[i][0] == 3:
                tempScore[combs[i][0]-1] += 3
            elif temp[i][1] == 3:
                tempScore[combs[i][1]-1] += 3
            else:
                tempScore[combs[i][0]-1] += 1
                tempScore[combs[i][1]-1] += 1

        if tempScore[T-1] == max(tempScore) and tempScore.count(max(tempScore)) == 1:
            count += 1

        return

    for i in scores:
        find(scores, temp+[i], m)


T = int(input())
G = int(input())

for i in range(G):
    Ta, Tb, Sa, Sb = map(int, input().split())

    if sorted([Ta, Tb]) in combs:
        combs.remove(sorted([Ta, Tb]))

        if Sa > Sb:
            score[Ta-1] += 3
        elif Sa < Sb:
            score[Tb-1] += 3
        else:
            score[Ta-1] += 1
            score[Tb-1] += 1

find([(0, 3), (3, 0), (1, 1)], [], 6-G)
print(count)
