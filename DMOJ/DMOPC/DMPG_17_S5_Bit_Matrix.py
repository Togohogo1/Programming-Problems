from math import log2, ceil


def find(gen, arr):
    if gen == 1:
        return arr

    rev = arr[::-1]

    for i in range(len(arr)):
        arr[i] = "0" + arr[i]
        rev[i] = "1" + rev[i]

    return find(gen-1, arr+rev)


R, C = map(int, input().split())

rows = find(ceil(log2(R+1)), ["0", "1"])
cols = find(ceil(log2(C+1)), ["0", "1"])

for i in range(R):
    for j in range(C):
        print(int(rows[i]+cols[j], 2), end=" ")

    print()
