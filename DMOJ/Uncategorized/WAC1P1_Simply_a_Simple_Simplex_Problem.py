import math

c = d = 0
graph = 0

for i in range(int(input())):
    graph = int(input())
    c = graph * 2

    graph = math.floor(math.sqrt(2 * graph))
    d = graph * graph + graph

    if c == 0:
        print(0)
        break
    elif d < c:
        print(graph + 2)
    else:
        print(graph + 1)
