num_l = num_o = num_v = num_e = 0

for i in input()[::-1]:
    if i == "e":
        num_e += 1
    elif i == "v":
        num_v += num_e
    elif i == "o":
        num_o += num_v
    elif i == "l":
        num_l += num_o

print(num_l)
