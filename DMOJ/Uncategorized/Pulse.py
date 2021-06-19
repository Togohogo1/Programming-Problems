N, S, T = map(int, input().split())

count = 0
t = []

for i in range(S, T + 1):
    t.append(i)

for i in range(N):
    times = int(input())

    if 2*times in t:
        count += 1

print(count)
