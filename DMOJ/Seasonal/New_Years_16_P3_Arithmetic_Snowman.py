N = int(input())
sb = sorted(list(map(int, input().split())), reverse=True)

m = 0
t = []

for t1 in range(N):
    for t2 in range(t1, N):
        if sb[t1] - sb[t2] > 0 and 2*sb[t2] - sb[t1] in sb:
            t.append(3 * sb[t2])
            break

print(max(t))
