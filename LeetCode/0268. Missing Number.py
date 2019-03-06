# 缺失数字
# https://leetcode-cn.com/problems/missing-number/

class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 等差数列前 n 项和减去数组之和
        
        return len(nums) * (len(nums) + 1) / 2 - sum(nums)        
        
        '''
        # 异或运算(位运算)，XOR：X ^ X = 0，X ^ 0 = X
        # 索引 i: 0 ~ N，异或一遍共 N+1 个数字，并且异或所有出现的数字
        # 那么相同的数字都变为 0，剩下的数字就是只出现一次的数字，即缺失的数字
        # 初始化为 N，这样才能把 0 ~ N 各个索引多异或一遍
        
        res = n = len(nums)
        for i in range(n):
            res ^= i
            res ^= nums[i]
        return res        
        '''
        '''
        # 让每一个元素都放在正确的 index 上，元素不等于其 index 的就是返回值
        
        if not nums or len(nums) == 0:
            return 0
        if len(nums) == 1:
            if nums[0] == 0:
                return 1
            else:
                return 0
        
        for i in range(len(nums)):
            tmp = nums[i]
            while tmp < len(nums) and nums[tmp] != tmp:
                nums[tmp], tmp = tmp, nums[tmp]
        for i in range(len(nums)):
            if nums[i] != i:
                return i
        return len(nums)      
        '''