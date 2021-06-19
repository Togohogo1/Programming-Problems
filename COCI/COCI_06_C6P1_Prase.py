from collections import defaultdict

warns = 0
kids = defaultdict(int)

for i in range(int(input())):
    tot = 0

    kid = input()
    kids[kid] += 1

    for i in kids:
        if i != kid:
            tot += kids[i]

    if kids[kid] - 1 > tot:
        warns += 1

print(warns)
