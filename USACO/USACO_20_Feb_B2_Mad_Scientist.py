count = 0
hold = False

chain = []

N = int(input())
A = input()
B = input()

for i in range(N):
    if A[i] == B[i]:
        chain.append(0)
    else:
        chain.append(1)

for i in range(N-1):
    if not hold:
        if chain[i] == 1:
            count += 1

    if chain[i] == 1:
        hold = True
    else:
        hold = False

print(count)
