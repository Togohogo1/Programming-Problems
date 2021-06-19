import operator
from collections import defaultdict

for i in range(5):
    winners = defaultdict(int)

    for i in range(5):
        scorename = list(map(str, input().split()))
        winners[" ".join(scorename[1:])] = int(scorename[0])

    winners = sorted(winners.items(), key=operator.itemgetter(1), reverse=True)

    for i in winners:
        print(i[0])
