from itertools import accumulate

Modes = []
Damage = [0]*1050


def minimumDamage(n, Modes):
    li = []
    temp = n

    if Modes == []:
        return n

    for i in Modes:
        if n == 0:
            return 0
        elif n <= 0:
            return n*-1
        elif n < i[1]:
            return 0
        else:
            n -= i[1]
            n *= (100-i[0])/100

            li.append(n)

            n = temp

    return min(i for i in li if i > 0)


hp, modes, ships = map(int, input().split())

for i in range(modes):
    defensesAS = list(map(int, input().split()))
    Modes.append(defensesAS)

# Prefix sum array here
for i in range(ships):
    timeStart, attackTime, damage = map(int, input().split())

    Damage[timeStart] += damage
    Damage[timeStart + attackTime] -= damage

Damage = list(accumulate(Damage))

for i in Damage:
    hp -= minimumDamage(i, Modes)

if hp > 0:
    print(f"{hp:0.2f}")
else:
    print("DO A BARREL ROLL!")
