for i in range(int(input())):
    N = int(input())
    A = int(input())
    B = int(input())
    C = int(input())

    if A+B+C < N:
        print(-1)
    else:
        N -= C

        if N < 0:
            print(0, 0, C+N)
        else:
            N -= B

            if N < 0:
                print(0, B+N, C)
            else:
                N -= A

                if N < 0:
                    print(A+N, B, C)
                else:
                    print(A, B, C)
