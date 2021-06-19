import operator

computers = {}

N = int(input())

for i in range(N):
    computer, ram, cpu, disk = map(str, input().split())
    computers[computer] = 2*int(ram) + 3*int(cpu) + int(disk)

sc = sorted(computers.items(), key=operator.itemgetter(1), reverse=True)

if N > 1 and sc[0][1] != sc[1][1]:
    print(f"{sc[0][0]}\n{sc[1][0]}")
elif N > 1 and sc[0][1] == sc[1][1]:
    print(f"{sorted([sc[0][0], sc[1][0]])[0]}\n{sorted([sc[0][0], sc[1][0]])[1]}")
elif N == 1:
    print(sc[0][0])
