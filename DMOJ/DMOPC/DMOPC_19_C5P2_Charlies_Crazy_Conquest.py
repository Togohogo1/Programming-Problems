N, H = map(int, input().split())

HPc = HPb = H
moves = [0]*2*N

for i in range(N):
    move, dmg = map(str, input().split())
    moves[2*i] = (move, int(dmg))

for i in range(N):
    move, dmg = map(str, input().split())
    moves[2*i + 1] = (move, int(dmg))

for i in range(len(moves)):
    # Charlie's turn
    if i % 2 == 0:
        if i == 0:
            if moves[i][0] == "A":
                HPb -= moves[i][1]
            elif moves[i][0] == "D":
                if moves[i+1][0] == "D":
                    HPc -= moves[i][1]
        else:
            if moves[i][0] == "A":
                if moves[i-1][0] == "A":
                    HPb -= moves[i][1]
            elif moves[i][0] == "D":
                if moves[i+1][0] == "D":
                    HPc -= moves[i][1]

    # Bot's turn
    else:
        if i == len(moves)-1:
            if moves[i][0] == "A":
                HPc -= moves[i][1]
            elif moves[i][0] == "D":
                HPb -= moves[i][1]
        else:
            if moves[i][0] == "A":
                if moves[i-1][0] == "A":
                    HPc -= moves[i][1]
            elif moves[i][0] == "D":
                if moves[i+1][0] == "D":
                    HPb -= moves[i][1]

    if HPc <= 0:
        print("DEFEAT")
        break
    elif HPb <= 0:
        print("VICTORY")
        break

else:
    print("TIE")
