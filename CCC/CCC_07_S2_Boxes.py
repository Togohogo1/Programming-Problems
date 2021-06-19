boxes = []
objects = []

for i in range(int(input())):
    dim = sorted(list(map(int, input().split())))
    boxes.append(dim)

for i in range(int(input())):
    dim = sorted(list(map(int, input().split())))
    objects.append(dim)

for i in objects:
    min_diff = 8000000001
    final = -1

    for j in boxes:
        if j[0] >= i[0] and j[1] >= i[1] and j[2] >= i[2]:
            min_diff = min(min_diff, abs(j[0]*j[1]*j[2] - i[0]*i[1]*i[2]))

            if abs(j[0]*j[1]*j[2] - i[0]*i[1]*i[2]) == min_diff:
                final = j[0]*j[1]*j[2]

    if final >= 0:
        print(final)
    else:
        print("Item does not fit.")
