latin = True

N = int(input())

rows = []
cols = [[] for i in range(N)]

for i in range(N):
    row = list(input())
    rows.append(row)

    for j in range(N):
        cols[i].append(row[j])

for i in range(N):
    for j in range(N):
        if rows[i].count(rows[i][j]) != 1 or cols[i].count(rows[i][j]) != 1:
            latin = False

if not latin:
    print("No")
else:
    if rows[0] == list(sorted(rows[0])) and cols[0] == list(sorted(cols[0])):
        print("Reduced")
    else:
        print("Latin")
