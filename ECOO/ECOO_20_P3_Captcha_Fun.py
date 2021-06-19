def cut(arr):
    for i in range(len(arr)):
        if "*" not in arr[0]:
            arr.remove(arr[0])
        else:
            break
    return arr[::-1]


def flip(arr):
    for i in arr:
        i = i[::-1]

    return list(map(list, zip(*arr)))[::-1]


def add(arr):
    if len(arr[0]) % 2 != 0 and (arr[0][0] == "*" or arr[0][0] == arr[0][-1] == "*"):
        arr.insert(0, list(len(arr[0])*"-"))
    if arr[-1][-1] == "*":
        arr.append(list(len(arr[-1])*"-"))

    return arr


def decipher(arr):
    t = m = b = tl = tr = bl = br = False
    h = len(arr)

    if len(arr[0]) == 1:
        return 1

    if "*" in arr[0]:
        t = True
    if "*" in arr[h//2]:
        m = True
    if "*" in arr[-1]:
        b = True

    for i in range(h):
        if 0 < i < h//2:
            if arr[i][0] == "*":
                tl = True
            if arr[i][-1] == "*":
                tr = True

        if h//2 < i < h-1:
            if arr[i][0] == "*":
                bl = True
            if arr[i][-1] == "*":
                br = True

    if [t, m, b, tl, tr, bl, br] == [1, 0, 1, 1, 1, 1, 1]:
        return 0
    if [t, m, b, tl, tr, bl, br] == [0, 0, 0, 0, 1, 0, 1]:
        return 1
    if [t, m, b, tl, tr, bl, br] == [1, 1, 1, 0, 1, 1, 0]:
        return 2
    if [t, m, b, tl, tr, bl, br] == [1, 1, 1, 0, 1, 0, 1]:
        return 3
    if [t, m, b, tl, tr, bl, br] == [0, 1, 0, 1, 1, 0, 1]:
        return 4
    if [t, m, b, tl, tr, bl, br] == [1, 1, 1, 1, 0, 0, 1]:
        return 5
    if [t, m, b, tl, tr, bl, br] == [1, 1, 1, 1, 0, 1, 1]:
        return 6
    if [t, m, b, tl, tr, bl, br] == [1, 0, 0, 0, 1, 0, 1]:
        return 7
    if [t, m, b, tl, tr, bl, br] == [1, 1, 1, 1, 1, 1, 1]:
        return 8
    if [t, m, b, tl, tr, bl, br] == [1, 1, 1, 1, 1, 0, 1]:
        return 9


for i in range(int(input())):
    for i in range(int(input())):
        H, W = map(int, input().split())

        captcha = []

        for i in range(H):
            captcha.append(list(input()))

        captcha = cut(cut(captcha))
        captcha = list(map(list, zip(*captcha[::-1])))
        captcha = add(flip(cut(cut(captcha))))

        print(decipher(captcha), end="")

    print()
