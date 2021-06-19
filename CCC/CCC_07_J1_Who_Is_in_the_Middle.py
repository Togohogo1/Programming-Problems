t = []

for i in range(3):
    t.append(int(input()))

t.remove(max(t))
t.remove(min(t))

print(t[0])
