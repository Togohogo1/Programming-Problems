import math
import sys
t = []


def NegabinToDec(li):
    final_sum = int()
    li.reverse()

    for i in range(len(li)):
        if li[i] == 1:
            final_sum += (-2)**i

    return final_sum


def DecToNegabin(n):
    li = []
    string = str()

    if n == 0:
        return 0
    while n != 0:
        c = n % 2
        n = math.ceil(n / -2)
        li.append(str(c))

    return string.join(li)[::-1]


b = []
N = int(input())

for i in range(N):
    a = list(map(str, input().split(" ")))
    b.append(a)

for i in b:
    if i[0] == "A":
        t.append(NegabinToDec(list(map(int, i[1]))))
    elif i[0] == "B":
        t.append(DecToNegabin(int(i[1])))

print(*t, sep='\n')
