def sieve(N):
    prime = []
    cross = [False] * (N+1)

    for i in range(2, N+1):
        if cross[i] == False:
            prime.append(i)

            for j in range(2*i, N+1, i):
                cross[j] = True

    return sum(prime)


for i in range(5):
    print(sieve(int(input())))
