d = 0
flag = False

temp = []


def shift(word):
    new = ""
    new2 = ""
    for i in range(0, len(word)):
        if i % 2 == 0:
            new += word[i]
        else:
            new2 += word[i]

    return new + new2[::-1]


a = int(input())
b = input()
c = b


for i in range(a):
    temp.append(b)
    b = shift(b)
    if temp.count(b) == 2:
        flag = True
        break

if flag == True:
    for i in range(a % (len(temp))):
        c = shift(c)
    print(c)
else:
    for i in range(a):
        c = shift(c)
    print(c)
