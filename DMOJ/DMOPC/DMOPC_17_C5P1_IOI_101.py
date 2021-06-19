new = ""

translate = {
    "0": "O",
    "1": "l",
    "3": "E",
    "4": "A",
    "5": "S",
    "6": "G",
    "8": "B",
    "9": "g"
}

for i in input():
    if i in translate:
        new += translate[i]
    else:
        new += i

print(new)
