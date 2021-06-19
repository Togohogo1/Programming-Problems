from collections import deque
import sys

input = sys.stdin.readline

N, T, K, V = map(int, input().split())

rests = [0]*N
window = deque()

for i in range(V):
    ai = int(input())
    rests[ai-1] = 1

ans = 0
curr = sum(rests[:T])

for i in range(T-1, -1, -1):
    if curr < K:
        if rests[i] == 0:
            window.appendleft(1)
            rests[i] = 1
            curr += 1
            ans += 1
        else:
            window.appendleft(0)
    else:
        window = deque(rests[:T])
        break

for i in range(T, N):
    if window[0] == 1:
        curr -= 1

    if rests[i] == 1:
        curr += 1

    window.popleft()
    window.append(rests[i])

    if curr < K:
        window[-1] = 1
        rests[i] = 1
        curr += 1
        ans += 1

print(ans)
