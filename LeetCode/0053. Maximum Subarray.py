# 最大子序和
# https://leetcode-cn.com/problems/maximum-subarray/

class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 动态规划，只关注 当前值 和 当前值+过去的状态是变好还是变坏
        # 到 i 处的最大值有两个可能：一个是加上 nums[i]，一个是从 nums[i] 重新开始
        
        n = len(nums)
        maxSum = [nums[0] for i in range(n)]
        for i in range(1, n):
            maxSum[i] = max(maxSum[i-1] + nums[i], nums[i])
        return max(maxSum)
        
        '''
        sum = 0
        max_sub_sum = nums[0]
        for num in nums:
            sum += num
            if sum > max_sub_sum:
                max_sub_sum = sum
            if sum < 0:
                sum = 0
        return max_sub_sum
        '''