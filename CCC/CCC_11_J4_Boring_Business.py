B = []
c = True

h = [[0 for i in range(400)] for i in range(200)]

# Move everything one back, subtract, get negative
h[4][199] = h[5][199] = h[6][199] = h[0][200] = h[1][200] = h[2][200] = h[6][200] = h[2][201] = h[6][201] = h[2][203] = h[2][203] = h[2][203] = h[3][203] = h[4][203] = h[6][203] = h[4][204] = h[6][204] = h[2][205] = h[3][205] = h[4][205] = h[6][205] = h[2][206] = h[6][206] = h[2][207] = h[3][207] = h[4][207] = h[5][207] = h[6][207] = 1

# Movement and detection
a = 4
b = 199

while True:
    A = list(map(str, input().split(" ")))

    # If the first letter is q
    if A[0] == "q":
        break
    if c == False:
        break

    if A[0] == "r":  # Right
        for j in range(int(A[1])):
            h[a][b + (j + 1)] += 1

            if h[a][b + (j + 1)] >= 2:
                c = False
                break
            else:
                c = True

        b += (int(A[1]))

    elif A[0] == "d":  # Down
        for j in range(int(A[1])):
            h[a + (j + 1)][b] += 1

            if h[a + (j + 1)][b] >= 2:
                c = False
                break
            else:
                c = True

        a += (int(A[1]))

    elif A[0] == "l":  # Left
        for j in range(int(A[1])):
            h[a][b - (j + 1)] += 1

            if h[a][b - (j + 1)] >= 2:
                c = False
                break
            else:
                c = True

        b -= (int(A[1]))

    elif A[0] == "u":  # Up
        for j in range(int(A[1])):
            h[a - (j + 1)][b] += 1

            if h[a - (j + 1)][b] >= 2:
                c = False
                break
            else:
                c = True

        a -= (int(A[1]))

    if c == False:
        B.append(str(str((b - 200)) + " " + str((a*-1 - 1)) + " DANGER"))
    else:
        B.append(str(str((b - 200)) + " " + str((a*-1 - 1)) + " safe"))

for i in B:
    print(i)
