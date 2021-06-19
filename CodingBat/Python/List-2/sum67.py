'''
Return the sum of the numbers in the array, except ignore sections of numbers
starting with a 6 and extending to the next 7 (every 6 will be followed by at
least one 7). Return 0 for no numbers.
'''

def sum67(nums):
    hold = False

    for i in range(len(nums)):
        if nums[i] == 6:
            nums[i] = 0
            hold = True
        elif hold and nums[i] != 7:
            nums[i] = 0
        elif hold and nums[i] == 7:
            nums[i] = 0
            hold = False

    return sum(nums)
