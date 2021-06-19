z = []

n = list(map(int, input().split(" ")))

z.append(0)
z.append(n[0])
z.append(n[0] + n[1])
z.append(n[0] + n[1] + n[2])
z.append(n[0] + n[1] + n[2] + n[3])

for i in range(5):
    print()

    for j in range(5):
        print(abs(z[i] - z[j]), end=" ")
