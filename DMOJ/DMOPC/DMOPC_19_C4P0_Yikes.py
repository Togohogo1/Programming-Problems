diff_counter = 0

A = input()
B = input()

for i in range(len(A)):
    if A[i] != B[i]:
        diff_counter += 1

if diff_counter > 1:
    print("LARRY IS DEAD!")
elif diff_counter == 1:
    print("LARRY IS SAVED!")
else:
    print("LARRY IS DEAD!")
