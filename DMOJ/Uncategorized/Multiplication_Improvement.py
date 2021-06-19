S = list(map(int, input().split("x")))
S.sort()

prod = 1
s = ""

for i in S:
    prod *= i
    s += f"{i}x"

print(s[:-1])
print(prod)
