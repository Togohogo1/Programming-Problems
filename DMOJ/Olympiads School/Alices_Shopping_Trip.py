c = 0
stores = []

T, N = map(int, input().split())

for i in range(N):
    stores.append(int(input()))

stores = sorted(stores, key=abs)

for i in range(N-1):
    c += abs(stores[i] - stores[i+1])

    if c >= T:
        print(i+1)
        break
else:
    print(N)
