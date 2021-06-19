N = int(input())
cows = input()

count = 0
flag = False

blanks = []

for i in range(N):
    if cows[i] == "0":
        flag = True
        count += 1

    if (cows[i] == "1" or i == N-1) and flag:
        blanks.append(count+1)
        flag = False
        count = 0

# One empty chain
if len(blanks) == 1:
    if cows[0] == cows[-1] == "1":
        print(blanks[0] // 3)
    elif cows[0] == "1" or cows[-1] == "1":
        print(blanks[0] // 2)
    else:
        print(blanks[0] - 2)

# Two empty chains
elif len(blanks) == 2:
    if cows[0] == cows[-1] == "0":
        print(min(blanks[0]-1, blanks[1]-1))
    else:
        print(min(blanks[0]//2, blanks[0]//2))

# More than 2 empty chains
else:
    dists = []

    # Case 1: (right, max1) and (left, max2)
    if blanks[-1] != max(blanks) and blanks[0] != max(blanks):
        b = blanks.copy()
        if cows[-1] == "1":
            b[b.index(max(b))] = max(b) // 2
            b[-1] //= 2
            dists.append(min(b))
        elif cows[-1] == "0":
            b[b.index(max(b))] = max(b) // 2
            b.pop(-1)
            dists.append(min(b))

        b = blanks.copy()
        if cows[0] == "1":
            b[b.index(max(b))] = max(b) // 2
            b[0] //= 2
            dists.append(min(b))
        elif cows[0] == "0":
            b[b.index(max(b))] = max(b) // 2
            b.pop(0)
            dists.append(min(b))

    # Case 2: (max1, max2), not including right and left
    b = blanks.copy()
    b.pop(0)
    b.pop(-1)

    if len(b) >= 4:
        b[b.index(max(b))] = max(b) // 2
        b[b.index(max(b))] = max(b) // 2
        dists.append(min(b))

    # Case 3: (right, left)
    b = blanks.copy()

    if cows[0] == "1" and cows[-1] == "1":
        b[0] //= 2
        b[-1] //= 2
        dists.append(min(b))
    elif cows[0] == "0" and cows[-1] == "1":
        b[-1] //= 2
        dists.append(min(b))
    elif cows[0] == "1" and cows[-1] == "0":
        b[0] //= 2
        dists.append(min(b))
    elif cows[0] == "0" and cows[-1] == "0":
        dists.append(min(b))

    # Case 4: (double)
    b = blanks.copy()
    b[b.index(max(b))] = max(b) // 3
    dists.append(min(b))

    print(max(dists))
