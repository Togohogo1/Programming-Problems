c = 0
new = []
flag = False

N = int(input())
seq = list(map(int, input().split()))

while c != N:
    if flag == True:
        break

    for i in range(1, seq[0]):
        new.append(i)
        new.append(seq[0] - i)

        for j in range(N-2):
            t = seq[j+1] - new[j+1]

            if t <= 0:
                break

            new.append(t)

        if len(set(new)) == N:
            print(" ".join(str(i) for i in new))
            flag = True
            break

        new = []

    c += 1
