from itertools import combinations as c

blocks = []
sums = []

N, T = map(int, input().split())
for i in range(N):
    blocks.append(int(input()))

if sum(blocks) < T:
    print(-1)
elif sum(blocks) == T:
    print(0)
else:
    for i in range(1, 20):
        sums += list(map(sum, c(blocks, i)))

    sums.sort()

    for i in sums:
        if i == T:
            print(0)
            break
        elif i > T:
            print(abs(T - i))
            break
