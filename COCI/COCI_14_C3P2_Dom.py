import sys
input = sys.stdin.readline

f_arr = [-1]*100001
h_arr = [-1]*100001
vis = [0]*100001

N, M, P = map(int, input().split())

for i in range(N):
    fav, hate = map(int, input().split())

    if f_arr[i+1] == -1:
        f_arr[i+1] = fav
    if h_arr[hate] == -1:
        h_arr[hate] = i+1

count = 0
curr = P
loop = False

while True:
    temp = h_arr[curr]

    if temp != -1:
        curr = f_arr[temp]
    else:
        break

    vis[curr] += 1
    count += 1

    if vis[curr] > 1:
        loop = True
        break

print(-1 if loop else count)
