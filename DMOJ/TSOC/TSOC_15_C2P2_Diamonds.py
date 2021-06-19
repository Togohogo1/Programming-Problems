N = int(input())

print("*"*N)

for i in range(N//2-1):
    print("*"*((N//2-i)) + " "*(N-2*(N//2-i)) + "*"*((N//2-i)))

print("*" + " "*(N-2) + "*")

for i in range(N//2-2, -1, -1):
    print("*"*((N//2-i)) + " "*(N-2*(N//2-i)) + "*"*((N//2-i)))

print("*"*N)
