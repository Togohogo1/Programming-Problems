c = 0

N = int(input())

a = list(map(str, input()))
b = list(map(str, input()))

for i in range(N):
    if a[i] == b[i] and a[i] == "C":
        c += 1

print(c)
