m = 2020001

for i in range(int(input())):
    lift = list(map(int, input().split()))
    m = min(m, sum(lift[1:]))

print(m)
