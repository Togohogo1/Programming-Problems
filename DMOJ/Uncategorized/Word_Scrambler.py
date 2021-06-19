from itertools import permutations

for i in permutations(sorted(input())):
    print("".join(i))
