def convertPSA(string, letter):
    psa = [0]
    count = 0

    for c in string:
        if c == letter:
            count += 1

        psa.append(count)

    return psa


psas = {}
S = list(input())
Q = int(input())

for letter in "abcdefghijklmnopqrstuvwxyz":
    psas[letter] = convertPSA(S, letter)

for i in range(Q):
    lower, upper, letter = input().split()
    lower, upper, letter = int(lower), int(upper), str(letter)

    print(psas[letter][upper] - psas[letter][lower-1])
