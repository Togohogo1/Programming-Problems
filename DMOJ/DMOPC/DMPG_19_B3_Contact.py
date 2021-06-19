a = input()
b = int(input())

count = 0
Max = True

if set(a) == {"S"} and b <= len(a):
    Max = False
else:
    for i in a:
        if count == b:
            Max = False
            break

        if i == "S":
            count += 1
        elif i == "R":
            count = 0

if Max == False:
    print("Spamming")
elif Max == True:
    print("All good")
