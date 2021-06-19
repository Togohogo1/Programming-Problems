def gcd(m, n):
    if n == 0:
        return m

    return gcd(n, m%n)


ans = 0
H, V = map(int, input().split())

for x in range(H):
    for y in range(1, V):
        mx, my = y//gcd(x, y), x//gcd(x, y)
        xx, yy = mx+x, my+y

        while xx <= H and yy <= V:
            ans += (H-xx) * (V-yy)
            xx += mx
            yy += my

print(ans)
