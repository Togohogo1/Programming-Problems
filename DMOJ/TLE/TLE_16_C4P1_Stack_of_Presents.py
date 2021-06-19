gifts = []

for i in range(int(input())):
    gifts.append(int(input()))

gifts.sort()

curr = 0
count = 0

for i in range(len(gifts)):
    if gifts[i] >= curr:
        curr += gifts[i]
        count += 1

print(count)
