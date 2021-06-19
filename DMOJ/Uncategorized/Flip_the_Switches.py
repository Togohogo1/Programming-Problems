c = 0

N = int(input())
Str = list(input())

for i in range(len(Str) - 1):
    if Str[i] != Str[i+1]:
        c += 1

if Str[len(Str)-1] == "0":
    print(c)
else:
    print(c+1)
