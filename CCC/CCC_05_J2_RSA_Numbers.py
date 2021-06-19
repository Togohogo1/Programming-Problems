def div4(n):
    b = 0
    for i in range(n):
        if n % (i+1) == 0:
            b += 1
    if b == 4:
        return 1
    else:
        return 0


b = 0

low = int(input())
high = int(input())

for i in range(low, high + 1):
    b += div4(i)

print("The number of RSA numbers between", low, "and", high, "is", b)
