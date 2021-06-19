a3 = int(input()) * 3
a2 = int(input()) * 2
a1 = int(input())

b3 = int(input()) * 3
b2 = int(input()) * 2
b1 = int(input())

if sum([a3, a2, a1]) > sum([b3, b2, b1]):
    print("A")
elif sum([a3, a2, a1]) < sum([b3, b2, b1]):
    print("B")
else:
    print("T")
