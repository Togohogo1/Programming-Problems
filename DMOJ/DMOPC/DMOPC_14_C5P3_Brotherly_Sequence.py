N = int(input())
S = list(map(int, input().split()))

temp = 1
bro = -1

for i in range(1, N):
    if abs(S[i-1] - S[i]) <= 2:
        temp += 1
    else:
        temp = 1

    bro = max(temp, bro)

print(bro)
