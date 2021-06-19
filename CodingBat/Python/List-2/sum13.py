'''
Return the sum of the numbers in the array, returning 0 for an empty array.
Except the number 13 is very unlucky, so it does not count and numbers that
come immediately after a 13 also do not count.
'''

def sum13(nums):
    nums.append(0)
    count = 0

    for i in range(len(nums)):
        if nums[i] == 13 and nums[i + 1] != 13:
            count -= (nums[i] + nums[i + 1])
        elif nums[i] == 13:
            count -= nums[i]

        count += nums[i]

    return count
