c = a = 0
q = []

N = list(map(int, input().split()))

for i in N:
    for j in N:
        for k in N:
            q.append(i)
            q.append(j)
            q.append(k)

            a = max(q)
            q.remove(max(q))

            if q[0] + q[1] > a and a != q[0] and a != q[1] and q[1] != q[0]:
                c += 1

            q = []

print(int(c/6))
