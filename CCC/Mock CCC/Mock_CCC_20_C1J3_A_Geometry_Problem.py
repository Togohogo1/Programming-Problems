X = int(input())
Y = int(input())

if X*Y % 4 == 1:
    print(f'{X*Y//4}.25')
elif X*Y % 4 == 2:
    print(f'{X*Y//4}.50')
elif X*Y % 4 == 3:
    print(f'{X*Y//4}.75')
else:
    print(f'{X*Y//4}.00')
