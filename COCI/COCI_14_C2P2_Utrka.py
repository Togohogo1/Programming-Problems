racers = {}

N = int(input())

for i in range(N):
    a = input()

    if a in racers:
        racers[a] += 1
    else:
        racers[a] = 1

for i in range(N-1):
    racers[input()] -= 1

print(list(racers.keys())[list(racers.values()).index(1)])
