import sys
input = sys.stdin.readline

N = int(input())
seq = list(map(int, input().split()))

fin = 0
tot = seq[0]

mr = [seq[-1]]
ml = [seq[0]]

for i in range(1, N):
    mr.append(max(seq[N-i-1], mr[i-1]))
    ml.append(max(seq[i], ml[i-1]))
    tot += seq[i]

mr.reverse()

for i in range(N):
    r = mr[i]
    l = ml[i]
    fin += min(l, r)

print(abs(tot-fin))
