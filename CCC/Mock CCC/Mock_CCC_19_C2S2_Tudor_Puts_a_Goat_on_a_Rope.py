import math

x, y, x1, y1, x2, y2 = map(int, input().split())

if min(y1, y2) <= y and max(y1, y2) >= y:
    print(f"{min(abs(x1-x), abs(x2-x)):.3f}")
elif min(x1, x2) <= x and max(x1, x2) >= x:
    print(f"{min(abs(y1-y), abs(y2-y)):.3f}")
else:
    print(f"{min((math.sqrt((x1-x)**2+(y1-y)**2)), (math.sqrt((x2-x)**2+(y2-y)**2)), (math.sqrt((x1-x)**2+(y2-y)**2)), (math.sqrt((x2-x)**2+(y1-y)**2))):.3f}")
