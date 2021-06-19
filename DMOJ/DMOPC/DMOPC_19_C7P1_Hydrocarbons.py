a, b, c, d = map(int, input().split())

s = a + b + c

if 2*s + d == 4*(s+1):
    print(f"C{s+1}H{d}")
else:
    print("invalid")
