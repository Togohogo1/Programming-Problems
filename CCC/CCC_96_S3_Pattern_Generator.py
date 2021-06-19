def perm(n, k):
    dft = "1"*k + "0"*(n-k)
    f_dft = list(reversed(dft))

    print(f"The bit patterns are\n{dft}")
    dft = list(dft)

    while dft != f_dft:
        for i in range(n-1, -1, -1):
            if dft[i] == "0" and dft[i-1] == "1":
                dft[i], dft[i-1] = dft[i-1], dft[i]
                dft = dft[:i+1] + list(reversed(dft[i+1:]))
                break

        print("".join(dft))


for i in range(int(input())):
    n, k = map(int, input().split())

    perm(n, k)
    print()
