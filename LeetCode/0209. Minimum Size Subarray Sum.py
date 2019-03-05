# 长度最小的子数组
# https://leetcode-cn.com/problems/minimum-size-subarray-sum/

class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        # 双指针
        
        start, end, sums = 0, 0, 0
        n = len(nums)
        # 先找到满足其和 >= s 的连续子数组
        while sums < s:
            if end == n:
                return 0
            sums += nums[end]
            end += 1
        # 对该子数组进行调整
        while True:
            sums -= nums[start]
            start += 1
            if sums < s:
                if end < n:
                    sums += nums[end]
                    end += 1
                else:
                    return end - start + 1
        
        '''
        start, end, sums, res = 0, 0, 0, sys.maxsize
        while end < len(nums):
            sums += nums[end]
            end += 1
            while sums >= s:
                sums -= nums[start]
                start += 1
                res = min(res, end - start + 1)
        return res if res != sys.maxsize else 0
        '''
