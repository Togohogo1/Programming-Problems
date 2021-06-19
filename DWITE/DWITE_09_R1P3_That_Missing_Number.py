for i in range(5):
    s = 0
    M = int(input())

    for i in range(M):
        s += int(input())

    print((M+1)*(M+2)//2 - s)
