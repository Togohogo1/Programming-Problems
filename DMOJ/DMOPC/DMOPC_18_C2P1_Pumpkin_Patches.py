a = []
y = []
x = []

P = int(input())

for i in range(P):
    xy = list(map(int, input().split(" ")))
    a.append(xy)

for i in range(P):
    y.append((a[i][1]))
    x.append((a[i][0]))

print(((max(y)-min(y)) + (max(x)-min(x)))*2)
