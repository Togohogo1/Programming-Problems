flag = True


def fact(D):
    factors = []

    for i in range(D, 0, -1):
        if D % i == 0:
            factors.append(i)

    return factors


N, D = map(int, input().split())
li_j = sorted(list(map(int, input().split())), reverse=True)

for i in fact(abs(D)):
    if not flag:
        break

    for j in li_j:
        if i % j == 0:
            print(abs(D) // j)
            flag = False
            break
else:
    print("This is not the best time for a trip.")
