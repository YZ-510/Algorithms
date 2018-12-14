# 移动零
# https://leetcode-cn.com/problems/move-zeroes/

class Solution:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        num = []
        for i in range(len(nums)):
            if nums[i] == 0:
                num.append(i)
        '''
        num 记录值为 0 的索引，nums 每删除一个 0，后面未删除的 0 的索引值就要减 1
        '''
        k = 0
        for j in range(len(num)):
            num[j] = num[j] - k
            nums.pop(num[j])
            nums.append(0)
            k = k + 1
        
        '''
        n = nums.count(0)
        for i in range(n):
            nums.remove(0)
            nums.append(0)
        '''