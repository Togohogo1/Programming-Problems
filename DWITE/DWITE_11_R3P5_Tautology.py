N_flag = False
tauts = []


def taut(arr, s):
    global N_flag

    if len(arr) == 10:
        temp = s

        for x, y in enumerate("ABCDEXGHIJ"):
            temp = temp.replace(y, arr[x])

        if not eval(temp):
            N_flag = True
            return

        return

    taut(arr + ["True"], s)
    taut(arr + ["False"], s)


for i in range(5):
    for i in range(3):
        tautology = input().upper().replace("F", "X").replace(
            "^", "and").replace("V", "or").replace("~", "not ")
        taut([], tautology)

        if N_flag:
            print("N", end="")
        else:
            print("Y", end="")

        N_flag = False

    print()
