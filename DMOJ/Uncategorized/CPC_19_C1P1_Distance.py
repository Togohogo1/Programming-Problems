N = int(input())

for i in range(N):
    if i % 2 == 1:
        print(N-i//2, end=" ")
    else:
        print(i//2+1, end=" ")
