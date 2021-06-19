import sys
input = sys.stdin.readline

N = int(input())
houses = input()

fin = 0
I = []

for i in range(N):
    if houses[i] == "1":
        I.append(i)

for i in range(len(I)-1):
    if (I[i+1]-I[i]) % 2 == 1:
        fin += ((I[i+1]-I[i]) // 2) * (((I[i+1]-I[i]) // 2) + 1)
    else:
        fin += ((I[i+1]-I[i]) // 2) * (((I[i+1]-I[i]) // 2) + 1) - ((I[i+1]-I[i]) // 2)

if I[0] != 0:
    fin += (I[0] * (I[0]+1)) // 2
if I[-1] != N:
    fin += ((N-I[-1]-1) * (N-I[-1])) // 2

print(fin)
