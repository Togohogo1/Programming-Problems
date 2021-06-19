win = False
curr = 1

while not win:
    n = int(input())

    if n == 0:
        print("You Quit!")
        break

    curr += n

    if curr == 9:
        curr += 25
    elif curr == 40:
        curr += 24
    elif curr == 67:
        curr += 19
    elif curr == 99:
        curr -= 22
    elif curr == 90:
        curr -= 48
    elif curr == 54:
        curr -= 35

    if curr > 100:
        curr -= n

    print(f"You are now on square {curr}")

    if curr == 100:
        print("You Win!")
        win = True
