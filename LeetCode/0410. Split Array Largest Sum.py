# 分割数组的最大值
# https://leetcode-cn.com/problems/split-array-largest-sum/

class Solution:
    def splitArray(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: int
        """
        # 二分查找，时间复杂度：O(n * logm)，n 为数组 nums 的长度，m 为数组 nums 的和
        # 将数组 nums 拆分成 m 个子数组，每个子数组的和大于等于 sum(nums)/m，小于等于 sum(nums) 
        
        high = sum(nums)
        low = high // m
        while low <= high:
            mid = (low + high) // 2
            n = m
            cnt = 0
            valid = True
            for i in range(len(nums)):
                if nums[i] > mid:       # 说明解在右区间，搜索右区间
                    valid = False
                    break
                if cnt + nums[i] > mid: # 进行分割，并初始化 n，cnt
                    n -= 1
                    cnt = 0
                cnt += nums[i]  # 统计每次分割的小区间的和
                if n == 0:      # n == 0 说明划分的区间数超过了 m，说明解在右区间，搜索右区间
                    valid = False
                    break
            if valid:
                high = mid - 1  # valid == True，搜索左区间
            else:
                low = mid + 1   # valid == False，搜索右区间
        return low
        
        '''
        # 贪心算法
        # left 是数组中的最大值，right 是数组和，通过 canSplit 改变 left 和 right，最终会收敛到一个值
        
        left = max(nums)
        right = sum(nums)
        while left < right:
            mid = (left + right) // 2
            if self.canSplit(nums, m, mid):
                right = mid
            else:
                left = mid + 1
        return left
    
    def canSplit(self, nums, m, sum_):
        cnt = 1
        cursum = 0
        for i in range(len(nums)):
            cursum += nums[i]
            if cursum > sum_:
                cursum = nums[i]
                cnt += 1
                if cnt> m:
                    return False
        return True        
        '''
