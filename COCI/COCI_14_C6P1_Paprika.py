A, B, A2, B2 = [], [], [], []
val_a = val_b = 0

N, X = map(int, input().split())

for i in range(N):
    a, b = map(int, input().split())
    A.append(a)
    A2.append(a)
    B.append(b)

# Original
for i in range(N):
    try:
        if A[0] > X and B[0] == 0:
            val_a += 1

            A.pop(0)
            B2.append(B.pop(0))

        elif A[0] <= X and B[0] == 1:
            val_a += 1

            A.pop(0)
            B2.append(B.pop(0))

        elif A[0] > X and B[0] == 1 and A[1] <= X and B[1] == 0 or A[0] < X and B[0] == 0 and A[1] >= X and B[1] == 1:
            A.pop(1)
            A.pop(0)
            B2.append(B.pop(1))
            B2.append(B.pop(0))

        else:
            A.pop(0)
            B2.append(B.pop(0))

    except IndexError:
        pass

for i in range(N):
    try:
        if A2[i] > X and B2[i] == 0:
            val_b += 1
        elif A2[i] <= X and B2[i] == 1:
            val_b += 1

    except IndexError:
        pass

print(max(val_a, val_b))
