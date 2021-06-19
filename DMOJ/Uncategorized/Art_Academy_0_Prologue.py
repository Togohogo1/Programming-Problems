N = int(input())

for i in range(N):
    S = input()

    for i in S:
        if i in {"a", "A"}:
            print("Hi!", end=" ")
        elif i in {"e", "E"}:
            print("Bye!", end=" ")
        elif i in {"i", "I"}:
            print("How are you?", end=" ")
        elif i in {"o", "O"}:
            print("Follow me!", end=" ")
        elif i in {"u", "U"}:
            print("Help!", end=" ")
        elif i in {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}:
            print("Yes!", end=" ")

    print()
