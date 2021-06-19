N = int(input())

a = int()
b = int()

colour_list = [0]*6  # [r, o, y, g, bl, ba]
colours = list(map(str, input().split()))

for i in colours:
    if i == "red":
        colour_list[0] += 1
    elif i == "orange":
        colour_list[1] += 1
    elif i == "yellow":
        colour_list[2] += 1
    elif i == "green":
        colour_list[3] += 1
    elif i == "blue":
        colour_list[4] += 1
    elif i == "black":
        colour_list[5] += 1

a = colour_list.pop(colour_list.index(max(colour_list)))
b = sum(colour_list)

print(min(a, b + 1) + b)
