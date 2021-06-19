c = 0

c_list = []
c_set = []
tot_scores = []

K, N = map(int, input().split())

for i in range(K):
    tot_scores.append(list(map(int, input().split())))

for i in tot_scores:
    for x in range(1, N+1):
        for y in range(1, N+1):
            if i.index(x) < i.index(y):
                c_list.append(str([x, y]))

for i in c_list:
    if c_list.count(i) == K:
        c_set.append(i)

print(len(set(c_set)))
