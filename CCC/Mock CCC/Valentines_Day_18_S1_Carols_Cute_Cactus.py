def palin(n):
    if str(n) == str(n)[::-1]:
        return True
    return False


N, M = map(int, input().split())

mid = (N+M) // 2
mid1 = (N+M) // 2
mid2 = (N+M) // 2

mids = {}

while True:
    mid1 += 1

    if palin(mid1):
        break

while True:
    mid2 -= 1

    if palin(mid2):
        break

if abs(mid - mid1) > abs(mid - mid2):
    print(mid2)
else:
    print(mid1)
