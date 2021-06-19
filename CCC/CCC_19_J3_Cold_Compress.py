# Makes all repeating values into one
def compress(N):
    N = list(N)

    newlist = []
    newlist.append(N.pop(0))

    while len(N) > 0:
        if newlist[-1] != N[0]:
            newlist.append(N[0])

        N.pop(0)

    return newlist


for i in range(int(input())):
    c = 0
    c_list = []

    chars = input()

    tempchar = list(chars)
    tempchar.append("placeholder")  # Prevent IndexError

    # Add 1 to c while input[i] equals to the compressed(input)[i]. # of times input[i] repeats
    for i in compress(tempchar)[:-1]:
        while tempchar[0] == i:
            c += 1
            tempchar.pop(0)

        c_list.append(c)
        c = 0

    for i in range(len(c_list)):
        print(c_list[i], compress(chars)[i], end=" ")

    print()
