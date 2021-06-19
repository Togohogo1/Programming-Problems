for i in range(5):
    words = list(map(str, input().split()))

    for i in words[::-1]:
        try:
            if int(i):
                print(i, end=" ")
        except ValueError:
            print(i[::-1], end=" ")

    print()
