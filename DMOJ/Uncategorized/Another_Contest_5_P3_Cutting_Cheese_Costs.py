final = 0

cheese = []
temp = []

N, K = map(int, input().split())

for i in range(N):
    p, d = map(int, input().split())

    temp.append(p-d)
    cheese.append(p)

temp.sort(reverse=True)

for i in range(K):
    final += temp[i]

print(sum(cheese) - final)
