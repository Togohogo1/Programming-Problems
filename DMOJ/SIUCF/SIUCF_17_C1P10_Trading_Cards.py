va = 0
vb = 0

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

m = int(input())
c = list(map(int, input().split()))
d = list(map(int, input().split()))

for i in range(n):
    va += a[i] * b[i]

for i in range(m):
    vb += c[i] * d[i]

print(va, vb)
