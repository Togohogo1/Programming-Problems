import sys
input = sys.stdin.readline

N = int(input())
total = 0

A, B = map(int, input().split())

GUID_A = list(map(int, input().split()))
GUID_B = list(map(int, input().split()))

GUID_Q = [0]*1_000_001

for i in GUID_A:
    GUID_Q[i] += 1
for i in GUID_B:
    GUID_Q[i] += 1

for i in GUID_Q:
    if i == 2:
        total += 1

print(N-total)