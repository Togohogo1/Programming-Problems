N = int(input())

if N == 0:
    print("Yes")
elif N >= 3:
    if N % 4 == 0 or (N//2 % 2 == 1 and N % 2 == 1):
        print("Yes")
    else:
        print("No")
else:
    print("No")
