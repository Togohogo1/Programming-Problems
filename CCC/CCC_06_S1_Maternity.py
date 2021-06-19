s = "AaBbCcDdEe"

t = []
t2 = []

p1 = input()
p2 = input()
n = int(input())

for i in range(n):
    if (p1[0 + 2*i] + p2[0 + 2*i]) == (s[0 + 2*i] + s[0 + 2*i]) or (p1[0 + 2*i] + p2[0 + 2*i]) == (s[1 + 2*i] + s[0 + 2*i]) or (p1[0 + 2*i] + p2[0 + 2*i]) == (s[0 + 2*i] + s[1 + 2*i]):
        t.append(s[0 + 2*i])
    else:
        t.append(s[1 + 2*i])

    if (p1[0 + 2*i] + p2[1 + 2*i]) == (s[0 + 2*i] + s[0 + 2*i]) or (p1[0 + 2*i] + p2[1 + 2*i]) == (s[1 + 2*i] + s[0 + 2*i]) or (p1[0 + 2*i] + p2[1 + 2*i]) == (s[0 + 2*i] + s[1 + 2*i]):
        t.append(s[0 + 2*i])
    else:
        t.append(s[1 + 2*i])

    if (p1[1 + 2*i] + p2[0 + 2*i]) == (s[0 + 2*i] + s[0 + 2*i]) or (p1[1 + 2*i] + p2[0 + 2*i]) == (s[1 + 2*i] + s[0 + 2*i]) or (p1[1 + 2*i] + p2[0 + 2*i]) == (s[0 + 2*i] + s[1 + 2*i]):
        t.append(s[0 + 2*i])
    else:
        t.append(s[1 + 2*i])

    if (p1[1 + 2*i] + p2[1 + 2*i]) == (s[0 + 2*i] + s[0 + 2*i]) or (p1[1 + 2*i] + p2[1 + 2*i]) == (s[1 + 2*i] + s[0 + 2*i]) or (p1[1 + 2*i] + p2[1 + 2*i]) == (s[0 + 2*i] + s[1 + 2*i]):
        t.append(s[0 + 2*i])
    else:
        t.append(s[1 + 2*i])

for i in range(n):
    kid = str(input())

    if kid[0] in t and kid[1] in t and kid[2] in t and kid[3] in t and kid[4] in t:
        t2.append("Possible baby.")
    else:
        t2.append("Not their baby!")

for i in range(n):
    print(t2[i])
