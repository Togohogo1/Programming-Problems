s = 0
nodes = []

for i in range(int(input())):
    b = int(input())

    nodes.append(b)
    s += b

if s % 2 == 1:
    print("NO")
else:
    for i in nodes:
        if s - i < i:
            print("NO")
            break
    else:
        print("YES")
