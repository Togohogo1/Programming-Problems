N, K, a, b = map(int, input().split())

if N > K:
    print(K*a + (N-K)*b)
elif N <= K:
    print((N)*a)
