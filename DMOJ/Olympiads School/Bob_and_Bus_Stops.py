import sys
input = sys.stdin.readline

def b_search(n):
    lo = -1
    hi = len(stops)
    mid = 0

    for i in range(30):
        mid = (hi+lo) // 2

        if stops[mid] > n:
            hi = mid
        elif stops[mid] < n:
            lo = mid

    return mid + 1


N, Q = map(int, input().split())
stops = list(map(int, input().split()))

stops.sort()

for i in range(Q):
    L, R = map(int, input().split())
    print(b_search(R) - b_search(L-1))
