N = int(input())

if N == 0:
    print(1)
elif N == 1:
    print(9)
elif N > 17:
    print(999999998)
elif N > 1 and N % 2 == 0:
    print(str(int("1"+(N//2-1)*"9"+"8") % 1000000000))
elif N > 1 and N % 2 == 1:
    print(str(int("10"+((N-3)//2)*"9"+"8") % 100000000))
