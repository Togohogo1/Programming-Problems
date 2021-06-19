ppl = [1]*7

N = int(input())

for i in range(N-1):
    ppl[int(input())] *= (ppl[i+1] + 1)

print(ppl[N])
