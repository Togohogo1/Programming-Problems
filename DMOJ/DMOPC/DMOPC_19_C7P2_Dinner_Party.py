N = int(input())
orders = list(map(int, input().split()))

shift = 0

while True:
    if orders[0] == min(orders):
        break

    orders = orders[1:] + orders[:1]
    shift += 1

val = min(orders[0], orders[-1])

for i in range(val+1):
    total = i
    moves = []
    copied = orders.copy()

    copied[0] -= i
    copied[-1] -= i
    moves.append([shift%N, (N-1+shift)%N, i])

    for i in range(N-1):
        new = min(copied[i], copied[i+1])

        copied[i] -= new
        copied[i+1] -= new

        total += new
        moves.append([(i+shift)%N, (i+1+shift)%N, new])

    if set(copied) == {0}:
        print("YES")
        print(total)

        for i in moves:
            for j in range(i[2]):
                print(i[0], i[1])

        break

else:
    print("NO")
