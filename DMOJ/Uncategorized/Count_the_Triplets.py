sComb = set()

N = int(input())
A = sorted(list(map(int, input().split())))

sA = set(A)

for i in range(len(A)):
    for j in range(len(A)):
        if A[i] + A[j] in sA and i != j:
            sComb.add((min(A[i], A[j]), max(A[i], A[j])))

if len(sComb) >= 1:
    print(len(sComb))
else:
    print(-1)
