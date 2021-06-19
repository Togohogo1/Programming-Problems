M = 1000000007

for i in range(int(input())):
    a1, a2, a3, k = map(int, input().split())

    if a3-a2 == a2-a1:
        print((a1 + (k-1)*(a2-a1)) % M)
    else:
        print((a1 * pow(a2//a1, k-1, M)) % M)
