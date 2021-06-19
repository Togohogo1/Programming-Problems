request2 = 0
count = 0

sizeslist = []

j, p = int(input()), int(input())

for i in range(j):
    sizes = input()
    if sizes == "S":
        sizeslist.append(0)
    elif sizes == "M":
        sizeslist.append(1)
    elif sizes == "L":
        sizeslist.append(2)

for i in range(p):
    request, size = input().split()
    if request == "S":
        request2 = 0
    elif request == "M":
        request2 = 1
    elif request == "L":
        request2 = 2

    size = int(size)

    if sizeslist[size-1] >= request2 and 1 <= size and size <= p:
        count += 1
        sizeslist[size-1] = -1

print(count)
