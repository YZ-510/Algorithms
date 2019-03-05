# 二分查找
# https://leetcode-cn.com/problems/binary-search/

class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        right = len(nums) - 1
        left = 0
        while left <= right:
            i = (left + right) // 2
            if nums[i] == target:
                return i
            elif nums[i] < target:
                left = i + 1
            else:
                right = i - 1
                
        return -1
