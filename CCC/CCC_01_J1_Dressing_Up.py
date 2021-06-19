num = int(input())

i = 1
while i < (num + 1):
    print('*'*i + ' '*(num - i) + ' '*(num - i) + '*'*i)
    i += 2

i = num - 2
while i > 0:
    print('*'*i + ' '*(num - i) + ' '*(num - i) + '*'*i)
    i -= 2
