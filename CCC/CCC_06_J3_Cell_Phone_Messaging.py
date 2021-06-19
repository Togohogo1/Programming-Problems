phone = {
    "a": 2, "b": 2, "c": 2,
    "d": 3, "e": 3, "f": 3,
    "g": 4, "h": 4, "i": 4,
    "j": 5, "k": 5, "l": 5,
    "m": 6, "n": 6, "o": 6,
    "p": 7, "q": 7, "r": 7, "s": 7,
    "t": 8, "u": 8, "v": 8,
    "w": 9, "x": 9, "y": 9, "z": 9,
    " ": 0
}

numPresses = {"adgjmptw": 1, "behknpux": 2, "cfilorvy": 3, "sz": 4}


def convert(numPresses, word, phone):
    totaltime = 0
    additionalTime = 0

    for i in numPresses:
        for j in word:
            if j in i:
                totaltime += numPresses[i]

    for i in range(len(word)-1):
        if phone[word[i]] == phone[word[i+1]]:
            additionalTime += 2

    return totaltime + additionalTime


while True:
    word = input() + " "

    if word == "halt ":
        break

    print(convert(numPresses, word, phone))
