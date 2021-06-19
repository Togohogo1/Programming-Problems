f = 0

num = int(input())
hobby = list(map(str, input().split(" ")))

for i in range(num):
    if len(hobby[i]) > 10:
        f += 1

print(num-f)
