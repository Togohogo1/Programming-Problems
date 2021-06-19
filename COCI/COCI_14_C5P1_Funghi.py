m = -1
s = []

for i in range(8):
    s.append(int(input()))

for i in range(8):
    t = s[i%8] + s[(i+1)%8] + s[(i+2)%8] + s[(i+3)%8]
    m = max(m, t)

print(m)
