C = 0
count = 0

cars = []

W = int(input())
N = int(input())

for i in range(N):
    cars.append(int(input()))

# Add 4 extra zeros to the beginning to add/subract one by one
for i in range(4):
    cars.insert(0, 0)

# Add 4th car, subtract the 0th car
for i in range(len(cars) - 4):
    C += cars[i + 4] - cars[i]

    if C > W:
        break
    else:
        count += 1

print(count)
