import sys
input = sys.stdin.readline

N = int(input())

front = list(map(int, input().split()))
side = list(map(int, input().split()))

freqf = [0]*1000001
freqs = [0]*1000001

len_f = len_s = N
count = 0

for i in front:
    freqf[i] += 1

for i in side:
    freqs[i] += 1

if max(front) != max(side):
    print(-1)
else:
    for i in range(1, max(front)+1):
        count += len_f*len_s

        len_f -= freqf[i]
        len_s -= freqs[i]

    print(count)
