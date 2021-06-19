d = []
r = []

N = int(input())
seq = list(map(int, input().split()))

for i in range(len(seq)-1):
    try:
        d.append(seq[i+1] - seq[i])
        r.append((seq[i+1] / seq[i]))
    except ZeroDivisionError:
        r.append(0)

if len(set(d)) > 1 and len(set(r)) > 1:
    print("random")
elif len(set(d)) == 1 and len(set(r)) != 1:
    print("arithmetic")
elif len(set(r)) == 1 and len(set(d)) != 1:
    print("geometric")
elif len(set(d)) == len(set(r)):
    print("both")
