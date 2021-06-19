count = 0
validLetters = "'QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm "

for i in range(5):
    newstring = b = c = ''

    for i in input():
        if i in validLetters:
            newstring += i

    newstring2 = newstring.split("'")

    for i in range(len(newstring2)):
        b += newstring2[i] + " "

    c = b.split(" ")

    for i in range(len(c)):
        if len(c[i]) > 3:
            count += 1

    print(count)
    count = 0
