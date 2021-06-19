a = ["A", "B", "C", "D", "E"]

while True:
    b = int(input())
    n = int(input())

    if b == 1:
        for i in range(n):
            b = a.pop(0)
            a.append(b)

    if b == 2:
        for i in range(n):
            b = a.pop(4)
            a.insert(0, b)

    if b == 3:
        for i in range(n):
            t = a[0]
            a[0] = a[1]
            a[1] = t

    if b == 4 and n == 1:
        break

for i in range(5):
    print(a[i], end=" ")
