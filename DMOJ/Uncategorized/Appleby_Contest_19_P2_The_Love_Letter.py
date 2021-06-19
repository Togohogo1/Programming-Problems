N = int(input())
L = int(input())
S = input()

for i in S:
    if i != " ":
        print(chr((ord(i)-97+L)%26 + 97), end="")
    else:
        print(" ", end="")
