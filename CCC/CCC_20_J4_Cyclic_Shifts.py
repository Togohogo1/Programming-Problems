T = input()
S = input()

for _ in range(len(S)):
    S = S[-1] + S[:-1]

    if S in T:
        print("yes")
        break

else:
    print("no")
