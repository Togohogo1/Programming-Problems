class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        fwd = [1]
        bwd = [1]
        ans = []

        for i in range(len(nums)):
            fwd.append(nums[i]*fwd[-1])
            bwd.append(nums[len(nums)-i-1]*bwd[-1])

        for i in range(len(nums)):
            ans.append(fwd[i]*bwd[len(nums)-i-1])

        return ans
