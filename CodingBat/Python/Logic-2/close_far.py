'''
Given three ints, a b c, return True if one of b or c is "close" (differing
from a by at most 1), while the other is "far", differing from both other
values by 2 or more. Note: abs(num) computes the absolute value of a number.
'''

def close_far(a, b, c):
    a = [a, b, c]
    a.sort()

    if abs(a[0] - a[1]) <= 1 and abs(a[1] - a[2]) <= 1:
        return False

    return True
