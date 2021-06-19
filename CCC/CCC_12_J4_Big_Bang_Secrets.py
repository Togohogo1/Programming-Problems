t = []

k = int(input())
wrd = str(input())

for i in wrd:
    t.append(ord(i))

for i in range(len(t)):
    b = t[i] - 3*(i+1) - k

    while b < 65:
        b += 26

    print(chr(b), end="")
