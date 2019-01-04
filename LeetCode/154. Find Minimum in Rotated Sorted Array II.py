# 寻找旋转排序数组中的最小值 II
# https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution:
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 跟 153 题类似，先把重复元素去掉即可
        
        lookup, new_nums = {}, []
        for num in nums:
            if num not in lookup:
                lookup[num] = 1
                new_nums.append(num)
        if len(new_nums) == 1:
            return nums[0]
        pivot = new_nums[0]
        for i in range(1, len(new_nums)):
            if new_nums[i] < pivot:
                return new_nums[i]
            pivot = new_nums[i]
        return new_nums[0]
        
        '''
        # 二分法
        
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] < nums[mid-1]:
                return nums[mid]
            elif nums[mid] > nums[right]:
                left = mid + 1
            elif nums[mid] < nums[left]:
                right = mid - 1
            elif left != right and nums[left] == nums[right]:
                left += 1
            else:
                return nums[left]       
        '''
        
        '''
        nums.sort()
        return nums[0]
        '''