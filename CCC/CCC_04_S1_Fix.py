for i in range(int(input())):
    a, b, c = input(), input(), input()

    if (a.startswith(b) or a.startswith(c) or a.endswith(b) or a.endswith(c) or
        b.startswith(a) or b.startswith(c) or b.endswith(a) or b.endswith(c) or
        c.startswith(a) or c.startswith(b) or c.endswith(a) or c.endswith(b)):
        print("No")

    else:
        print("Yes")
