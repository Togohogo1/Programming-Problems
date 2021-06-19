from math import ceil

for i in range(int(input())):
    n, a, b, t = map(int, input().split())

    ans = (t+b*n)/(a+b)

    if ans > n:
        print(-1)
    else:
        print(ceil(ans))
