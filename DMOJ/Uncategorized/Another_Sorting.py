curr = 0
li = []
temp = []

N = int(input())
a = list(map(str, input().split()))

for i in a:
    li.append([int(i[-1]), int(i)])

li.sort()
curr = li[0][0]

for i in li:
    if i[0] == curr:
        temp.append(i[1])
    else:
        for j in reversed(sorted(temp)):
            print(j, end=" ")

        temp = [i[1]]
        curr = i[0]

for i in reversed(sorted(temp)):
    print(i, end=" ")
