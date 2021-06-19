import sys
input = sys.stdin.readline


# Finding the smallest radius of infection possible
def radius(arr):
    m = 1000001
    prev = 2

    for i in range(1000001):
        if arr[i] != 0:

            # if prev state same as current state, (1, 1) or (-1, -1) skip.
            # Otherwise, it is the distance from a 1 to a -1
            if prev != 2 and arr[prev] != arr[i] and i - prev < m:
                m = i - prev

            # Storing the previous result
            prev = i

    return m


# Finding how many separations btw healthy and infected
def gaps(arr):
    ans = 0
    prev = 0

    for i in range(1000001):
        if arr[i] != 0:

            # Counts sequences that are (infected to healthy) and (start to cow state)
            if arr[i] != prev and arr[i] == 1:
                ans += 1

            prev = arr[i]

    return ans


# A length larger than radius in each separation splits it again
def split(arr, rad):
    ans = 0
    prev = 2

    for i in range(1000001):
        if arr[i] != 0:

            # if current index - previous index larger than radius
            # Both indices cannot be 1
            if prev != 2 and arr[prev] != -1 and arr[i] != -1 and i - prev > rad:
                ans += 1

            prev = i

    return ans


# Keeping distances between cows accurate
cows = [0 for i in range(1000001)]

for i in range(int(input())):
    x, s = map(int, input().split())

    if s == 1:
        cows[x] = 1
    elif s == 0:
        cows[x] = -1

print(gaps(cows) + split(cows, radius(cows)-1))
