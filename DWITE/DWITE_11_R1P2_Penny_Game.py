for i in range(5):
    ans = 0
    coins = []

    for i in range(int(input())):
        coins.append(int(input()))

    avg = sum(coins) // len(coins)

    for i in coins:
        ans += abs(avg - i)

    print(ans // 2)
