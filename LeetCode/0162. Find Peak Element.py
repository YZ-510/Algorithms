# 寻找峰值
# https://leetcode-cn.com/problems/find-peak-element/comments/

class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 二分法，如果中间的是峰值直接返回，否则，两边较大的那一侧存在峰值
        
        if len(nums) == 1:
            return 0
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > nums[mid + 1]:
                right = mid
            else:
                left = mid + 1
        return left
        
        '''
        left = 0
        right = len(nums) - 1
        while left <= right:
            if left == right:
                return left
            mid = (left + right) // 2
            if nums[mid] < nums[mid + 1]:
                left = mid + 1
            else:
                right = mid
        '''
