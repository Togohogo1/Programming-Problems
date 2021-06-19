import math

for i in range(5):
    a = int(input())

    if a == 0:
        print(1)
    elif abs(pow(2, math.ceil(math.log(a) / math.log(2))) - a) <= abs(pow(2, math.floor(math.log(a) / math.log(2))) - a):
        print(pow(2, math.ceil(math.log(a) / math.log(2))))
    else:
        print(pow(2, math.floor(math.log(a) / math.log(2))))
