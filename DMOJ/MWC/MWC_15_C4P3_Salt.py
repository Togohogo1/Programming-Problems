import sys
from collections import defaultdict

input = sys.stdin.readline

is_salty = []
X_salt = defaultdict(int)
Y_salt = defaultdict(int)

N, Q = map(int, input().split())

for i in range(N):
    salt_x, salt_y = map(int, input().split())

    is_salty.append((salt_x, salt_y))
    X_salt[salt_x] += 1
    Y_salt[salt_y] += 1

for i in range(Q):
    q, a, b = map(str, input().split())

    if q == "1":
        if (int(a), int(b)) in is_salty:
            print("salty")
        else:
            print("bland")
    else:
        if a == "X":
            print(X_salt[int(b)])
        else:
            print(Y_salt[int(b)])
