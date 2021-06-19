def diff(li):
    for i in range(len(li)-1, 0, -1):
        li[i] = li[i]*(i+1) - li[i-1]*(i)

    return li


input()
arr = diff(list(map(int, input().split())))

for i in arr:
    print(i, end=" ")
