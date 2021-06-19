d = []
s = []

while True:
    d.append(str(input()))
    s.append(str(input()))

    if s[-1] == "SCHOOL":
        break

d.reverse()
s.reverse()

s.pop(0)
s.append("HOME")

for i in range(len(d)):
    if d[i] == "R":
        d.pop(i)
        d.insert(i, "LEFT")
    if d[i] == "L":
        d.pop(i)
        d.insert(i, "RIGHT")

for i in range(len(d) - 1):
    print("Turn", d[i], "onto", s[i], "street.")

print("Turn", d[len(d)-1], "into your HOME.")
