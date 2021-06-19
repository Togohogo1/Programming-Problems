roman = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}

letters = []
mult_vals = []

AR = input()

for i in range(len(AR)):
    if i % 2 == 0:
        mult_vals.append(int(AR[i])*roman[AR[i+1]])
    if i % 2 == 1:
        letters.append(AR[i])

for i in range(1, len(letters)):
    if roman[letters[i]] > roman[letters[i-1]]:
        mult_vals[i-1] *= -1

print(sum(mult_vals))
