b = ""
t = []

letters = ["q", "w", "r", "t", "p", "s", "d", "f", "g", "h", "j", "k", "l", "z", "x", "c", "v", "b", "n", "m"]

while True:
    a = input()
    t.append(a)

    if a == "quit!":
        break

t.pop(len(t) - 1)

for i in t:
    if i[-2:] == ("or") and len(i) > 4 and i[len(i)-3] in letters:
        print(i[:(len(i)-2)] + "our")
    else:
        print(i)
