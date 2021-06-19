N, M, X = map(int, input().split())

nums = list(map(int, input().split()))
denums = list(map(int, input().split()))

s = sum(nums)
m = 101
ans = -1

for i in denums:
    if max(nums) > i:
        continue
    else:
        if 100*(s/(i*N)) < 50:
            continue

        m = min(m, X - 100*(s/(i*N)))

        if X - 100*(s/(i*N)) == m:
            ans = i

if ans == -1:
    print("Shimnanigans have failed")
else:
    print(ans)
