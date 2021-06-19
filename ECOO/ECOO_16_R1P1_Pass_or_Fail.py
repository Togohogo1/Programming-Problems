for i in range(10):
    c = 0

    Wt, Wa, Wp, Wq = map(int, input().split())

    for i in range(int(input())):
        T, A, P, Q = map(int, input().split())
        if T*Wt + A*Wa + P*Wp + Q*Wq >= 5000:
            c += 1

    print(c)
