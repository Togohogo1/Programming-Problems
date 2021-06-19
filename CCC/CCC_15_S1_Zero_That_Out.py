n = 0
t = 0

x = []

n = int(input())

for i in range(n):
    t = int(input())
    x.append(t)

    if t == 0:
        x.pop(len(x)-1)
        x.pop(len(x)-1)

print(sum(x))
