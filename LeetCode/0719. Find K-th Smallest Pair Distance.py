# 找出第 k 小的距离对
# https://leetcode-cn.com/problems/find-k-th-smallest-pair-distance/

class Solution:
    def smallestDistancePair(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def getCount(mid):
            count, left = 0, 0
            for i in range(len(nums)):
                while nums[i] - nums[left] > mid:
                    left += 1
                count += i - left
            return count        
        
        nums.sort()
        left, right = 0, nums[-1] - nums[0]
        while left < right:
            mid = (left + right) // 2
            count = getCount(mid)   # 计数
            if count < k:           # 若 count 小于 k，mid 肯定不是最终解
                left = mid + 1
            else:                   # 若 count 大于等于 k，可以将 mid 作为候选解
                right = mid
        return left
