count = 0
jam = False

li_x = []
li_y = []

N, M = map(int, input().split())
A = int(input())

for i in range(A):
    x, y = map(int, input().split())
    li_x.append(x)
    li_y.append(y)

while True:
    try:
        if count == li_x[0]:
            li_x.pop(0)
            N += li_y[0]
            li_y.pop(0)
    except:
        pass

    if N > M:
        jam = True
        break

    N -= 1

    if N < 0:
        break

    count += 1

if jam == True:
    print(f"The printer jams at {count} second(s).")
else:
    print(f"The printer melts at {count+1} second(s).")
