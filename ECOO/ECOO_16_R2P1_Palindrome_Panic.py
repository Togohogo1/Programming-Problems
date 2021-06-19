# Uses the longest prefix size array (also longest suffix size) and the KPM algorithm
def LPS(string):
    M = len(string)
    lps = [None]*M

    length = 0
    lps[0] = 0
    i = 1

    while i < M:
        if string[i] == string[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1

    return lps


def palindrome(string):
    revStr = string[::-1]

    concat = string[::-1] + "!" + revStr[::-1]
    concat2 = string + "!" + revStr

    lps = LPS(concat)
    lps2 = LPS(concat2)

    return len(string) - max(lps[-1], lps2[-1])


for i in range(10):
    print(palindrome(input()))
