j = 0
c = 0
A = []

N, K = map(int, input().split())

for i in range(N):
    A.append(int(input()))

A.sort(reverse=True)

for i in A:
    c += i
    j += 1

    if c >= K:
        break

print(j)
