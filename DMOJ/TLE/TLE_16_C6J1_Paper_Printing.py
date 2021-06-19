order = {}

for i in range(int(input())):
    order[input()] = []

for i in range(int(input())):
    order[input()].append(i+1)

for i in order:
    for j in order[i]:
        print(j)
