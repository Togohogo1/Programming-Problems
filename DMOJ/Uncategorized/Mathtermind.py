from itertools import combinations as c


class Guess:
    def __init__(self, guess, right):
        self.guess = guess
        self.right = right


rate = 0
comb = ""
game = []

for i in range(int(input())):
    N, M = map(int, input().split())
    arr = list(map(int, input().split()))
    game.append(Guess(arr, M))

for i, j, k in c(range(1, 16), 3):
    for g in game:
        tmp = 0

        for n in g.guess:
            if n == i or n == j or n == k:
                tmp += 1

        if tmp != g.right:
            break

    else:
        comb = f"{i} {j} {k}"
        rate += 1

if rate == 0:
    print(-1)
elif rate == 1:
    print(comb)
else:
    print(rate)
