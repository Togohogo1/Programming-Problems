'''
Given an array of ints, return True if the array contains a 2 next to a 2
somewhere.
'''

def has22(nums):
    return "22" in "".join(map(str, nums))
