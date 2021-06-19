c = []

N = int(input())

for i in range(N):
    l = int(input())
    arr1 = list(map(int, input().split()))
    arr2 = list(map(int, input().split()))

    for j in range(len(arr2)):
        for i in range(len(arr1)):
            if arr2[l-j-1] >= arr1[i]:
                c.append(l-j-1-i)
                break
            else:
                c.append(0)

    print("The maximum distance is", max(c))

    c = []
