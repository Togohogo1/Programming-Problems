A = B = 0

while True:
    cmd = list(map(str, input().split()))

    if cmd[0] == "1":
        if cmd[1] == "A":
            A = int(cmd[2])
        else:
            B = int(cmd[2])

    elif cmd[0] == "2":
        if cmd[1] == "A":

            print(A)
        else:
            print(B)

    elif cmd[0] == "3":
        if cmd[1] == "A":
            if cmd[2] == "A":
                A += A
            elif cmd[2] == "B":
                A += B

        else:
            if cmd[2] == "A":
                B += A
            elif cmd[2] == "B":
                B += B

    elif cmd[0] == "4":
        if cmd[1] == "A":
            if cmd[2] == "A":
                A *= A
            elif cmd[2] == "B":
                A *= B

        else:
            if cmd[2] == "A":
                B *= A
            elif cmd[2] == "B":
                B *= B

    elif cmd[0] == "5":
        if cmd[1] == "A":
            if cmd[2] == "A":
                A -= A
            elif cmd[2] == "B":
                A -= B

        else:
            if cmd[2] == "A":
                B -= A
            elif cmd[2] == "B":
                B -= B

    elif cmd[0] == "6":
        if cmd[1] == "A":
            if cmd[2] == "A":
                A //= A
            elif cmd[2] == "B":
                A //= B

        else:
            if cmd[2] == "A":
                B //= A
            elif cmd[2] == "B":
                B //= B

    elif cmd[0] == "7":
        break
