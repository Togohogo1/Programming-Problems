N, Q = map(int, input().split())
acorns = list(map(int, input().split()))

for i in range(Q):
    t, l, r = map(int, input().split())

    if t == 1:
        acorns[l-1:r] = list(sorted(acorns[l-1:r]))
    else:
        acorns[l-1:r] = list(sorted(acorns[l-1:r], reverse=True))

print(*acorns)
