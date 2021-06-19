heightN = int(input())
heightM = int(input())

count = 0

for i in range(heightM):
    Heights = int(input())

    if heightN <= Heights:
        count += 1

print(count)
