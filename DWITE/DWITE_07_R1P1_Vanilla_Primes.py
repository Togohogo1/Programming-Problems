N = int(input())

for i in range(2, N):
    if N % i == 0:
        print("not")
        break

if N < 0 or N == 0 or N == 1:
    print("not")
else:
    print("prime")
