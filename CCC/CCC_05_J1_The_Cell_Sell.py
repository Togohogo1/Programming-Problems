day = int(input())
evn = int(input())
wkd = int(input())

a = day - 100
b = day - 250

if a < 0:
    a = 0
else:
    a = day - 100

if b < 0:
    b = 0
else:
    b = b - 250

print("Plan A costs", "%.2f" % (0.25*(a) + 0.15*evn + 0.20*wkd))
print("Plan B costs", "%.2f" % (0.45*(b) + 0.35*evn + 0.25*wkd))

if (0.25*(a) + 0.15*evn + 0.20*wkd) < (0.45*(b) + 0.35*evn + 0.25*wkd):
    print("Plan A is cheapest.")
elif (0.25*(a) + 0.15*evn + 0.20*wkd) > (0.45*(b) + 0.35*evn + 0.25*wkd):
    print("Plan B is cheapest.")
else:
    print("Plan A and B are the same price.")
