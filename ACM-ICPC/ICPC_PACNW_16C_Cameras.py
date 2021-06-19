from collections import deque
import sys

input = sys.stdin.readline

n, k, r = map(int, input().split())

rests = [0]*n
window = deque()

for i in range(k):
    ai = int(input())
    rests[ai-1] = 1

ans = 0
curr = sum(rests[:r])

for i in range(r-1, -1, -1):
    if curr < 2:
        if rests[i] == 0:
            window.appendleft(1)
            rests[i] = 1
            curr += 1
            ans += 1
        else:
            window.appendleft(0)
    else:
        window = deque(rests[:r])
        break

for i in range(r, n):
    if window[0] == 1:
        curr -= 1

    if rests[i] == 1:
        curr += 1

    window.popleft()
    window.append(rests[i])

    if curr < 2:
        window[-1] = 1
        rests[i] = 1
        curr += 1
        ans += 1

print(ans)
