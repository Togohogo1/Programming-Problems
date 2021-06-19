q = ""

c = {}
d = []
e = []

for i in range(int(input())):
    b = list(map(str, input().split(" ")))

    c[b[1]] = b[0]
    d.append(b[1])

s = input()

for i in s:
    q += i

    if q in d:
        e.append(c[q])
        q = ""

for i in e:
    print(i, end="")
