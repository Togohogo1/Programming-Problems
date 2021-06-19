import math


def diff_arr(li):
    diff = []
    for i in range(1, len(li)):
        diff.append(li[i] - li[i-1])

    return diff


count = 0
patt_set = 0

temperatures = []
patt_repeat = []

while True:
    temp = list(map(int, input().split()))

    if temp == [0]:
        break

    temp.pop(0)

    diff_li = diff_arr(temp)

    if len(temp) > 1:
        for i in range(1, len(diff_li)+1):
            patt_repeat = diff_li[:i] * math.ceil(len(diff_li)/i)

            for j in range(len(diff_li)):
                patt_set += 1

                if diff_li[j] != patt_repeat[j]:
                    patt_set = 0
                    break

            if patt_set == len(diff_li):
                print(i)
                patt_set = 0
                break
    else:
        print(0)
