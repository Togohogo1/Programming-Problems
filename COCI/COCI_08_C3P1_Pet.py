contestants = [0]*5

for i in range(5):
    contestants[i] = sum(list(map(int, input().split())))

print(contestants.index(max(contestants))+1, max(contestants))
