n = []

for i in range(5):
    n.append(input())

for i in n:
    for j in i:
        if i.count(j) == 1:
            print(j)
            break
