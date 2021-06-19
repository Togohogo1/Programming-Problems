N, L = map(int, input().split())

time = 0
temp = 0

for _ in range(N):
    D, R, G = map(int, input().split())
    time += D - temp
    temp = D

    if (time//(R+G))*(R+G) + R > time:
        time += (R - time) % (R+G)

print(L-D+time)
