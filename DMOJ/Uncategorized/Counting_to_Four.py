suffix = ["billion", "million", "thousand", ""]
to_word = {1: "one", 2: "two", 3: "three", 4: "four", 5: "five", 6: "six", 7: "seven", 8: "eight", 9: "nine",
           10: "ten", 11: "eleven", 12: "twelve", 13: "thirteen", 14: "fourteen", 15: "fifteen", 16: "sixteen", 17: "seventeen", 18: "eighteen", 19: "nineteen",
           20: "twenty", 30: "thirty", 40: "forty", 50: "fifty", 60: "sixty", 70: "seventy", 80: "eighty", 90: "ninety",
           100: "onehundred", 200: "twohundred", 300: "threehundred", 400: "fourhundred", 500: "fivehundred", 600: "sixhundred", 700: "sevenhundred", 800: "eighthundred", 900: "ninehundred"
           }


def int_to_word(n):
    n = str(n)
    s = ""

    for i in range(len(n)):
        # If it appears in the dictionary
        if int(n[i:]) in to_word:
            s += to_word[int(n[i:])]
            break

        # Makes 431 into 400 + 30 + 1
        else:
            s += to_word[int(n[i]) * (10**(len(n)-1-i))]

    return s


def split(n):
    t = ""
    split_number = []
    n = list(reversed(list(str(n))))

    # Responsible for splitting into groups of 3 numbers
    while len(n) > 0:
        s = ""

        for _ in range(3):
            if len(n) == 0:
                break

            s += (n.pop(0))

        split_number.append(s[::-1])

    splitted = list(reversed(split_number))

    # Fill in the extra 000s
    for i in range(4 - len(splitted)):
        splitted.insert(0, "000")

    # Adding the suffixes
    for i in range(4):
        if splitted[i] not in {"0", "00", "000"}:
            t += int_to_word(int(splitted[i])) + suffix[i]

    return t


N = int(input())

while N != 4:
    # Only needs to be executed once
    if N > 999:
        N = len(split(N))
        print(N)

    # After re-adding, number will not exceed 999
    else:
        N = len(int_to_word(N))
        print(N)
