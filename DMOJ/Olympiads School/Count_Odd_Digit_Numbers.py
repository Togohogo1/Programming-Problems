from math import ceil

arr = [0, 2, 4, 6, 8, 10, 12, 14, 16, 18]
ans = 0

N = int(input())
l = len(str(N))

if l % 2 == 0:
    for i in range(ceil(l/2)):
        ans += 9*10**arr[i]
else:
    for i in range(l//2):
        ans += 9*10**arr[i]

    ans += N - (10**(l-1)) + 1

print(ans)
