N, K = map(int, input().split())

if K > N//2:
    print(*range(N, N//2, -1), *range(N//2, K-N//2+1, -1), *range(K-N//2, 0, -1), str(K-N//2 + 1))
else:
    print(*range(N, N-K, -1), *range(K+1, N-K+1), *range(K, 0, -1))
