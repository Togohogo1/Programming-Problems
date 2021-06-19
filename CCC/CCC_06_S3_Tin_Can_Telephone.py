class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y


def seg(p, a, b):
    if min(a.x, b.x) <= p.x <= max(a.x, b.x) and min(a.y, b.y) <= p.y <= max(a.y, b.y):
        return True

    return False


def orient(p1, p2, p3):
    val = (p2.y-p1.y)*(p3.x-p2.x) - (p2.x-p1.x)*(p3.y-p2.y)

    if (val > 0):
        return 1
    elif (val < 0):
        return 2
    else:
        return 0


def intersect(p1, q1, p2, q2):
    if orient(p1, q1, p2) != orient(p1, q1, q2) and orient(p2, q2, p1) != orient(p2, q2, q1):
        return True
    if orient(p1, q1, p2) == 0 and seg(p2, p1, q1):
        return True
    if orient(p1, q1, q2) == 0 and seg(q2, p1, q1):
        return True
    if orient(p2, q2, p1) == 0 and seg(p1, p2, q2):
        return True
    if orient(p2, q2, q1) == 0 and seg(q1, p2, q2):
        return True

    return False


count = 0

xr, yr, xj, yj = map(int, input().split())
p1 = Point(xr, yr)
q1 = Point(xj, yj)

for i in range(int(input())):
    build = list(map(int, input().split()))
    b = build[1:] + [build[1], build[2]]

    for i in range(build[0]):
        p2 = Point(b[2*i], b[2*i + 1])
        q2 = Point(b[2*(i+1)], b[2*(i+1) + 1])

        if intersect(p1, q1, p2, q2):
            count += 1
            break

print(count)
