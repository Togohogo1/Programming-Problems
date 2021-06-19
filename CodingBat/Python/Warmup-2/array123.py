'''
Given an array of ints, return True if the sequence of numbers 1, 2, 3
appears in the array somewhere.
'''

def array123(nums):
    if "123" in "".join(map(str, nums)):
        return True

    return False
