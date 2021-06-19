N, C = map(int, input().split())

for i in range(N):
    name, score = map(str, input().split())

    if int(score) > C:
        print(f"{name} will advance")
    else:
        print(f"{name} will not advance")
