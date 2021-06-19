def split(word, n):
    splitted = []
    w = ""

    for i in range(1, len(word)+1):
        w += word[i-1]
        if i % n == 0 or i == len(word):
            splitted.append(w)
            w = ""

    return splitted


for _ in range(10):
    W = int(input())
    essay = list(map(str, input().split()))

    s = ""
    polished = []

    for i in range(len(essay)):
        if len(essay[i]) > W:
            polished += split(essay[i], W)
        else:
            polished.append(essay[i])

    for i in polished:
        s += i + " "

        if len(s.strip()) > W:
            print()
            s = i + " "

        print(i, end=" ")

    print("\n=====")
