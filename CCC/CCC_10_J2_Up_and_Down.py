t1 = []
t2 = []

u1 = 0
u2 = 0

a = int(input())
b = int(input())
c = int(input())
d = int(input())
s = int(input())

for i in range(s):
    for i in range(a):
        t1.append(1)
    for i in range(b):
        t1.append(-1)

for i in range(s):
    u1 += t1[i]

for i in range(s):
    for i in range(c):
        t2.append(1)
    for i in range(d):
        t2.append(-1)

for i in range(s):
    u2 += t2[i]

if u1 > u2:
    print("Nikky")
elif u1 < u2:
    print("Byron")
else:
    print("Tied")
