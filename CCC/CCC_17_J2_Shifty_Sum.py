n = int(input())
k = int(input())

c = n

for i in range(k):
    n *= 10
    c += n

print(c)
