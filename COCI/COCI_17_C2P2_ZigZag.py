from collections import defaultdict

words = defaultdict(list)
let_mod = defaultdict(int)

K, N = map(int, input().split())

for i in range(K):
    word = input()
    c1 = word[0]

    words[c1].append(word)
    let_mod[c1] = 0

for i in words:
    words[i].sort()

for i in range(N):
    let = input()
    n = let_mod[let] % len(words[let])

    temp = words[let][n]
    curr = words[let][n]
    let_mod[let] += 1

    print(temp)
