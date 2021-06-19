N = int(input())

for i in range(N):
    hexa = input()

    if hexa[2] in "13579BDF":
        print(hexa[:2] + chr(ord(hexa[2]) - 1) + hexa[3:], end=" ")

    print(hexa)
