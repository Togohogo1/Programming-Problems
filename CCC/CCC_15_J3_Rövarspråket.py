import operator

cons = "bcdfghjklmnpqrstvwxyz"
vowels = "aeiou"
newWord = ""


def convert(letter, vowels, cons):
    if letter in cons:
        a = {}
        b = []

        vowels = list(map(ord, vowels))
        cons = list(cons)

        for i in range(len(vowels)):
            a[vowels[i] - ord(letter)] = abs(vowels[i] - ord(letter))

        a = sorted(a.items(), key=operator.itemgetter(1))

        for i in range(2):
            b.append(a.pop(0))

        if letter == "z":
            temp = "z"
        else:
            temp = cons[cons.index(letter)+1]

        return letter + chr(ord(letter) + int(b[0][0])) + temp

    else:
        return letter


word = input()

for i in word:
    newWord += convert(i, vowels, cons)

print(newWord)
