dvs = []

for i in range(9):
    dvs.append(int(input()))

for i in dvs:
    for j in dvs:
        if i != j and i + j == sum(dvs) - 100:
            dvs.remove(i)
            dvs.remove(j)
            break

print(*dvs)
