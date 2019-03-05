# 寻找旋转排序数组中的最小值
# https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/

class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] < nums[mid - 1]:
                return nums[mid]
            elif nums[mid] < nums[left]:
                right = mid - 1
            elif nums[mid] > nums[right]:
                left = mid + 1
            else:
                return nums[left]
                
        '''
        # 一次遍历，遇到降序就找到了最小值
        
        if len(nums) == 1:
            return nums[0]
        pivot = nums[0]
        for i in range(1, len(nums)):
            if nums[i] < pivot:
                return nums[i]
            pivot = nums[i]
        return nums[0]    
        '''
