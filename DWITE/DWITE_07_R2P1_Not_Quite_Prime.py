prime = []
cross = [False]*1001

for i in range(2, 1001):
    if cross[i] == False:
        prime.append(i)

        for j in range(2*i, 1001, i):
            cross[j] = True

for i in range(5):
    n = int(input())

    for i in range(1, n):
        if i in prime and n//i in prime and n % 1 == 0:
            print("semiprime")
            break
    else:
        print("not")
