arr_a = []
arr_z = []

a = input()

for i in range(len(a)):
    if a[i] == "A":
        arr_a.append(i)
    elif a[i] == "Z":
        arr_z.append(i)

print(max(arr_z) - min(arr_a) + 1)
