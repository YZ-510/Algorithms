# 存在重复元素 III
# https://leetcode-cn.com/problems/contains-duplicate-iii/

class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        if t == 0 and len(nums) == len(set(nums)):
            return False
        for i in range(len(nums)):
            j = i + 1
            while j < len(nums) and j <= i + k:
                if abs(nums[i] - nums[j]) <= t:
                    return True
                j += 1
        return False