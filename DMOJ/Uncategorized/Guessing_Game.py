import math

guess, lo, hi = map(int, input().split())
count = 0

while True:
    count += 1
    t = (hi + lo)//2

    if t < guess:
        lo = t
    elif t > guess:
        hi = t
    elif t == guess:
        print(count)
        break
