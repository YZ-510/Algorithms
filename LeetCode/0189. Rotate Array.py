# 旋转数组
# https://leetcode-cn.com/problems/rotate-array/

class Solution:
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        # k 如果大于 nums 的长度了，只需进行 k % len(nums) 次就行了
        k = k % len(nums)
        if k != 0:
            temp = nums[-k:]
            for i in range(len(nums)-1, k-1, -1):
                nums[i] = nums[i-k]
            nums[:k] = temp
