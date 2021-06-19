items = []
required = []
count = 0
flag = True
N, M = map(int, input().split())
for i in range(N):
    items.append(input())

for i in range(M):
    for i in range(int(input())):
        required.append(input())
    for i in required:
        if i not in items:
            flag = False

    if flag == True:
        count += 1

    required = []
    flag = True

print(count)