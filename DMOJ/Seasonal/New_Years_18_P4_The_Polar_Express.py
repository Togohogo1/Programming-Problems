def find(dig_len, tot, shift):
    # A negative digit sum does not count
    if tot < 0:
        return 0

    # dp[0][0] always 1
    if dig_len == 0:
        return tot == 0

    if dp[tot][dig_len] != -1:
        return dp[tot][dig_len]

    ans = 0

    # looping up to each individual digit in number
    loop = digits[dig_len] if shift else 9

    for i in range(loop+1):
        # If true, continues to be true
        if digits[dig_len] == i and shift:
            ans += find(dig_len-1, tot-i, True)
        else:
            ans += find(dig_len-1, tot-i, False)

    dp[tot][dig_len] = ans
    return ans


def convert(n):
    global digits, dig_len

    digits = [0]
    dig_len = 0

    for i in str(n):
        digits.insert(1, int(i))
        dig_len += 1

    return digits, dig_len


ans = 0
dig_len = 0

la = []
lb = []
digits = [0]
dp = []

L, R = map(int, input().split())

convert(R)

for i in range(1, 163):
    dp = [[-1 for i in range(19)] for i in range(163)]
    la.append(find(dig_len, i, True))

convert(L-1)

for i in range(1, 163):
    dp = [[-1 for i in range(19)] for i in range(163)]
    lb.append(find(dig_len, i, True))

for i, j in zip(la, lb):
    ans += j < i

print(ans)
