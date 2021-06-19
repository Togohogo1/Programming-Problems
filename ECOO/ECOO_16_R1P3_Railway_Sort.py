for _ in range(10):
    N = int(input())
    cars = list(map(int, input().split()))

    count = 0

    for i in range(N, 1, -1):
        if cars.index(i) < cars.index(i-1):
            count += cars.index(i-1)
            cars.insert(0, cars.pop(cars.index(i-1)))

    print(count)
