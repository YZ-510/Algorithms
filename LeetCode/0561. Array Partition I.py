# 数组拆分
# https://leetcode-cn.com/problems/array-partition-i/

class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        return sum(nums[::2])
        
        '''
        nums = sorted(nums)
        num = 0
        for i in range(0, len(nums)-1, 2):
            num += nums[i]
        return num
        '''
