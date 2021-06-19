min_benefit = 0
max_benefit = 0
temp = 0

ppl_on = []
ppl_off = []

stops = int(input())

for i in range(stops-1):
    on, off = map(int, input().split())
    ppl_on.append(on)
    ppl_off.append(off)

min_benefit = ppl_on[0] - sum(ppl_off)
max_benefit = ppl_on[0] - ppl_off[1]

for i in range(1, stops-2):
    temp += ppl_on[i] - ppl_off[i+1]

if temp < 0:
    max_benefit += temp

if min_benefit < 0:
    min_benefit = 0
if max_benefit < 0:
    max_benefit = 0

print(min_benefit)
print(max_benefit)
