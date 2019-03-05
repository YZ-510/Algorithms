# 在排序数组中查找元素的第一个和最后一个位置
# https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # 找到相等的值时，左右指针合并，分别向左、右遍历寻找开始和结束索引
        
        if nums == [] or nums[0] > target or nums[-1] < target:
            return [-1, -1]
        
        left, right = 0, len(nums) -1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                left = right = mid
                while left - 1 >= 0 and nums[left - 1] == target:
                    left = left - 1
                while right + 1 < len(nums) and nums[right + 1] == target:
                    right = right + 1
                return [left, right]
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
                
        return [-1, -1]
