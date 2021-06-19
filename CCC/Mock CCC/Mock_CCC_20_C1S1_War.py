count = 0

N = int(input())

deck1 = list(map(int, input().split()))
deck2 = list(map(int, input().split()))

for i in range(1, N):
    if deck1[i] == deck2[i] and deck1[i-1] != deck2[i-1]:
        count += 1

if deck1[0] == deck2[0]:
    count += 1

print(count)
