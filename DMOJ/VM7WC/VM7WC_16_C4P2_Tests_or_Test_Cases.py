def find(idx, word):
    if idx == sets or len(word) == length:
        found.append(word)
        return 0

    for i in strings[idx]:
        find(idx+1, word+i)


global sets, length, strings

strings = []
found = []

sets, length = map(int, input().split())

for i in range(sets):
    line = list(input().split())
    if i >= 1:
        line[0] = ""
        strings.append(line)
    else:
        strings.append(line[1:])

find(0, "")

for i in sorted(found):
    print(i)
