N, D = map(int, input().split())
ppl = list(map(int, input().split()))

for i in range(D):
    n = int(input())

    F = sum(ppl[:n])
    S = sum(ppl[n:])

    if F >= S:
        print(F)
        ppl = ppl[n:]
    elif F < S:
        print(S)
        ppl = ppl[:n]
