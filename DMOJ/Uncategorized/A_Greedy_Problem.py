import sys

packages = []
final_cost = 0

factories, total = map(int, sys.stdin.readline().split())

for i in range(factories):
    cost, boxes = map(int, sys.stdin.readline().split())
    packages.append([cost, boxes])

packages.sort()

for i in packages:
    if total - i[1] > 0:
        total -= i[1]
        final_cost += i[0]*i[1]
    else:
        final_cost += i[0]*(total)
        break

print(final_cost)
