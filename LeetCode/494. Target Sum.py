# 目标和
# https://leetcode-cn.com/problems/target-sum/

class Solution(object):
    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        # 递归
        # findSum ：从索引 start_idx 开始向后的子集有几种得到 S 的方法
        def findSum(s, start_idx):
            if start_idx == len(nums):
                if s == 0:
                    return 1
                else:
                    return 0
            if (s, start_idx) not in cache:
                cache[(s, start_idx)] = findSum(s + nums[start_idx], start_idx + 1) + findSum(s - nums[start_idx], start_idx + 1)
            return cache[(s, start_idx)]
        
        cache = {}
        return findSum(S, 0)
        
        '''
        # 动态规划
        # 数组 nums 的两个子集 X、Y，X 的正 sum、Y 的负 sum 之和为 S
        # 即：sum(X) - sum(Y) = S、sum(X) + sum(Y) = sum(nums)
        # 问题变成寻找子集 X，使得 sum(X) = (S + sum(nums)) / 2
        # dp[i] 表示能够找出几个子集的 sum 等于 i，dp[0] = 1 空集的和为 0
        
        def subsetSum(s):
            dp = [0] * (s + 1)
            dp[0] = 1
            for i in range(len(nums)):
                for j in range(s, nums[i] - 1, -1):
                    dp[j] += dp[j - nums[i]]
            return dp[-1]
            
        if sum(nums) < S or (S + sum(nums)) % 2 > 0:
            return 0
        return subsetSum((S + sum(nums)) / 2)
        '''