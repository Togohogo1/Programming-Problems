'''
Given 2 ints, a and b, return their sum. However, sums in the range 10..19
inclusive, are forbidden, so in that case just return 20.
'''

def sorta_sum(a, b):
    return a + b if (a + b) < 10 or (a + b) > 19 else 20
