c = 0
final_let = []

N = int(input())
letters = input()

for i in letters:
    if i == "X":
        c -= 1
    elif c == 0:
        final_let.append(i)
    else:
        final_let[c] = i
        c = 0

for i in final_let:
    name = input()

    if i == "A":
        print(f"Dear {name}, beloved artist, I would love to have you at my party. Come to my crib on April 20th.")
    elif i == "O":
        print(f"Dear {name}, beloved occasion enthusiast, come to my crib to celebrate this very special day.")
    elif i == "R":
        print(f"Dear {name}, April 20th is happening again this year. Don't miss out.")
