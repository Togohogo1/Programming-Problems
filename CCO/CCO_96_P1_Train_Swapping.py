def moves(arr, n):
    ans = 0

    for i in range(1, n+1):
        ans += arr.index(i)-i+1
        arr.insert(i-1, arr.pop(arr.index(i)))

    return ans


for i in range(int(input())):
    L = int(input())
    perm = list(map(int, input().split()))

    print(f"Optimal train swapping takes {moves(perm, L)} swaps.")
