b = []

for i in range(int(input())):
    num = int(input())
    b.append(num)

for i in b:
    for i in (str(bin(i))[2:]):
        if i == "1":
            print("dank", end=" ")
        else:
            print("meme", end=" ")
    print()
