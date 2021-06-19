s1 = s2 = s3 = 0

a = input()
N = int(input())

Dspeed = list(map(int, input().split(" ")))
Pspeed = list(map(int, input().split(" ")))

if a == "1":
    for i in range(N):
        s1, s2 = max(Dspeed), max(Pspeed)
        s3 += max(s1, s2)

        Dspeed.remove(s1)
        Pspeed.remove(s2)

    print(s3)

else:
    for i in range(N):
        s1, s2 = max(Dspeed), min(Pspeed)
        s3 += max(s1, s2)

        Dspeed.remove(s1)
        Pspeed.remove(s2)

    print(s3)
