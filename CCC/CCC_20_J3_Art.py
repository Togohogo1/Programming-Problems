x = []
y = []

for i in range(int(input())):
    coords = list(map(int, input().split(",")))
    x.append(coords[0])
    y.append(coords[1])

print(f"{min(x)-1},{min(y)-1}")
print(f"{max(x)+1},{max(y)+1}")
