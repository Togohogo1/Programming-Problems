coefficients = []

n = int(input())

for i in range(n + 1):
    cf = float(input())

    if i < 2:
        coefficients.append(cf)

print(-coefficients[1] / (n*coefficients[0]))
