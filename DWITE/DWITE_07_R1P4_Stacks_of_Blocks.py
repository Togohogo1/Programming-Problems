def combs(tot, idx, n, val):
    if n == 0:
        if sum(tot) == val:
            possible.append(len(tot))

        return

    if idx == len(arr):
        return

    else:
        combs(tot+[arr[idx]], idx+1, n-1, val)
        combs(tot, idx+1, n, val)


arr = []
possible = []

H = int(input())
S = int(input())

for i in range(S):
    arr.append(int(input()))

for i in range(1, 10):
    combs([], 0, i, H)

print(0 if not possible else min(possible))
