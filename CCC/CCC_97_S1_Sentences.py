a = []
b = []
c = []

n = int(input())

for i in range(n):
    sub = int(input())
    vrb = int(input())
    obj = int(input())

    for i in range(sub):
        SUB = str(input())
        a.append(SUB)

    for i in range(vrb):
        VRB = str(input())
        b.append(VRB)

    for i in range(obj):
        OBJ = str(input())
        c.append(OBJ)

    for i in a:
        for j in b:
            for k in c:
                print(i, j, k + '.')

    print()

    a = []
    b = []
    c = []
