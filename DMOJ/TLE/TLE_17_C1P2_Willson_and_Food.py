from collections import defaultdict

foods = defaultdict(int)
dists = defaultdict(list)

for i in range(int(input())):
    food, energy = input().split()
    foods[food] = int(energy)

for i in range(int(input())):
    food_item, dist = input().split()

    # A dictionary of lists - net sum at any position
    dists[int(dist)].append(foods[food_item])

locations = sorted(dists)

count = 0
enr = 0
last = 0

for curr in locations:
    enr -= (curr - last)  # Difference between positions

    # Energy used up, can't move
    if enr < 0:
        break

    enr += sum(dists[curr])  # Net sum
    count += len(dists[curr])  # Number of food pieces

    last = curr  # Moving forward

print(count)