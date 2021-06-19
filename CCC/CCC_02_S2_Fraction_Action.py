a = int(input())
b = int(input())


# Reverse loop makes sure the gcf is reached
def gcf(a, b):
    for i in range(min(a, b)+1, 1, -1):
        if a%i == 0 and b%i == 0:
            return i
    else:
        return 1


if a%b == 0 and a//b == 0:  # 0
    print(0)
elif a%b == 0 and a//b != 0: # a
    print(a//b)
elif a%b != 0 and a//b == 0:  # b/c
    print(str((a%b) // gcf(a%b, b)) + "/" + str((b) // gcf(a%b, b)))
elif a%b != 0 and a//b != 0:  # a+b/c
    print(a//b, str((a%b) // gcf(a%b, b)) + "/" + str((b) // gcf(a%b, b)))
