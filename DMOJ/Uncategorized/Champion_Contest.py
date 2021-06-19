from bisect import bisect_left

n, k = map(int, input().split())
score = list(map(int, input().split()))

s_score = score.copy()
s_score.sort()

friends = [0 for i in range(100002)]

for i in range(k):
    a, b = map(int, input().split())

    if score[a-1] > score[b-1]:
        friends[a-1] += 1
    else:
        friends[b-1] += 1

for i in range(n):
    print(bisect_left(s_score, score[i]) - friends[i], end=" ")
