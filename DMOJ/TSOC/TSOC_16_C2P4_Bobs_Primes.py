def sieve(N):
    cross = [False] * (N+1)
    prime = []

    for i in range(2, N+1):
        if cross[i] == False:
            prime.append(i)

            for j in range(2*i, N+1, i):
                cross[j] = True

    return prime


cash = int(input())
obj = int(input())

times = [0 for _ in range(cash+1)]
comp = [[] for _ in range(cash+1)]
items = []
primes = sieve(10000)

temp = 0
end = False

for _ in range(obj):
    items.append(int(input()))

for i in range(1, cash+1):
    m = 1000000

    for j in range(obj):
        if i - items[j] >= 0:
            m = min(m, times[i-items[j]] + 1)

            if times[i-items[j]] + 1 == m:
                temp = items[j]

    times[i] = m

    if temp != 0:
        comp[i] += [temp] + comp[i-temp]

for i in primes:
    if i < cash and i >= sum(items)*2:
        if end:
            break

        if i - sum(comp[i]) == 0:
            for j in set(comp[i]):
                if comp[i].count(j) in primes:
                    print("its primetime")
                    end = True
                    break
        else:
            print("not primetime")
            break
else:
    print("not primetime")
