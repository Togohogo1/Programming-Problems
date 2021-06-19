import math

a = 1
b = 0

N = int(input())

if N == 0:
    print(f"{1:.4f}")
    print(f"{0:.4f}")
elif N >= 86:
    print(0.4383)
    print(0.3606)
else:
    for i in range(N):
        new_a = math.e**(-0.5*math.pi*(b))*math.cos((math.pi*(a))/2)
        new_b = math.e**(-0.5*math.pi*(b))*math.sin((math.pi*(a))/2)

        a = new_a
        b = new_b

    print(f"{a:.4f}")
    print(f"{b:.4f}")
