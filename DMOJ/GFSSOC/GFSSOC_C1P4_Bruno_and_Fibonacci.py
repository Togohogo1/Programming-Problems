N = int(input())
S = input()

A = 0
not_A = 0

fib = [1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377]

for i in range(1, N+1):
    if i in fib and S[i-1] == "A":
        A += 1
    if i not in fib and S[i-1] != "A":
        not_A += 1

if A + not_A == N:
    print("That's quite the observation!")
else:
    print("Bruno, GO TO SLEEP")
