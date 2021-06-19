from math import floor, ceil

tempstr = ""
base = []


def vertical(li):
    for i in li:
        if i[:floor(len(li)/2)] != list(reversed(i[ceil(len(li)/2):])):
            return False
    else:
        return True


def horizontal(li):
    for i in zip(*li[::-1]):  # For i CW 90 degrees of li
        if list(i[:floor(len(li)/2)]) != list(reversed(i[ceil(len(li)/2):])):
            return False
    else:
        return True


def diagonalUD(li):  # Comparing CW 90 degrees of li with original
    li2 = list(zip(*li[::-1]))

    for i in range(len(li)):
        if li[i] != list(reversed(li2[i])):
            return False
    else:
        return True


def diagonalDU(li):  # Comparing CCW 90 degrees of li with original
    li2 = list(zip(*li[::-1]))

    for i in range(2):
        li2 = list(zip(*li2[::-1]))

    for i in range(len(li)):
        if li[i] != list(reversed(li2[i])):
            return False
    else:
        return True


def upper_and_lower(li):
    uplow = []

    for i in li:
        uplow.insert(0, i)

    return uplow


def right_and_left(li):
    rightleft = []

    for i in li:
        rightleft.append(list(reversed(i)))

    return rightleft


N = int(input())

for i in range(N):
    base.append(list(input()))

if vertical(base) or horizontal(base) or diagonalDU(base) or diagonalUD(base):
    for i in range(N):  # Printing the upper part
        for j in range(N-1, -1, -1):
            tempstr += str(upper_and_lower(base)[i][j]) + " "
        for j in range(N):
            tempstr += str(upper_and_lower(base)[i][j]) + " "
        for j in range(N-1, -1, -1):
            tempstr += str(upper_and_lower(base)[i][j]) + " "

        print(tempstr[:-1])
        tempstr = ""

    for i in range(N):  # Printing the middle part
        for j in range(N):
            tempstr += str(right_and_left(base)[i][j]) + " "
        for j in range(N):
            tempstr += str(base[i][j]) + " "
        for j in range(N):
            tempstr += str(right_and_left(base)[i][j]) + " "

        print(tempstr[:-1])
        tempstr = ""

    for i in range(N):  # Printing the bottom part
        for j in range(N-1, -1, -1):
            tempstr += str(upper_and_lower(base)[i][j]) + " "
        for j in range(N):
            tempstr += str(upper_and_lower(base)[i][j]) + " "
        for j in range(N-1, -1, -1):
            tempstr += str(upper_and_lower(base)[i][j]) + " "

        print(tempstr[:-1])
        tempstr = ""

else:
    print("Offer Denied")
