'''
Given 2 int values, return True if one is negative and one is positive.
Except if the parameter "negative" is True, then return True only if both are
negative.
'''

def pos_neg(a, b, negative):
    if a*b < 0:
        if negative:
            return False

        return True

    else:
        if a and b < 0 and negative:
            return True

        return False
