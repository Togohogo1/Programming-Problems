ans = ""
N = input()

for i in range(int(len(N)**0.5), 0, -1):
    if len(N) % i == 0:
        break

for x in range(i):
    for y in range(0, len(N), i):
        ans += N[y+x]

print(ans)
