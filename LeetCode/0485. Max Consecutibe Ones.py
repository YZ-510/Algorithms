# 最大连续 1 的个数
# https://leetcode-cn.com/problems/max-consecutive-ones/

class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # j 当前连续 1 的个数
        # n 当前最大连续 1 的个数
        n, j = 0, 0
        for i in nums:
            if i == 0:
                if n < j:
                    n = j
                j = 0
            else:
                j += 1
                
        # 数组末尾出现连续 1，需再加一次判断        
        if n < j:
            return j
        else:
            return n
