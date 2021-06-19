for i in range(5):
    dd, mm, yyyy = map(int, input().split())

    if ((yyyy < 1999) or (yyyy == 1997 and mm < 10) or (yyyy == 1999 and mm == 10 and dd <= 27)):
        print("too young")
    else:
        print("old enough")
