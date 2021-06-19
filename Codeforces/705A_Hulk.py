n = int(input())

if n == 1:
    print("I hate it")
else:
    if n % 2 == 0:
        for i in range(n-1):
            if i % 2 == 0:
                print("I hate that", end=" ")
            else:
                print("I love that", end=" ")

        print("I love it")

    else:
        for i in range(n-1):
            if i % 2 == 0:
                print("I hate that", end=" ")
            elif i % 2 == 1:
                print("I love that", end=" ")

        print("I hate it", end=" ")
