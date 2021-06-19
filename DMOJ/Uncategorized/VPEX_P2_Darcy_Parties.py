mistakes = 0

N = int(input())
cakes = list(map(int, input().split()))

for i in cakes:
    if i != sum(cakes)//N:
        mistakes += 1

print(mistakes)
