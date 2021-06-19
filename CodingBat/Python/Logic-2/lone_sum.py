'''
Given 3 int values, a b c, return their sum. However, if one of the values is
the same as another of the values, it does not count towards the sum.
'''

def lone_sum(a, b, c):
    a = [a, b, c]
    a.sort()

    if a[0] != a[1] != a[2]:
        return sum(a)
    elif a[0] == a[2] == a[2]:
        return 0
    elif a[0] == a[1]:
        return a[2]
    elif a[1] == a[2]:
        return a[0]
