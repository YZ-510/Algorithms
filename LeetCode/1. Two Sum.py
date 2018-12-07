class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        dict = {}
        for i, num in enumerate(nums):
            if target-num in dict:
                return [dict[target-num], i]
            else:
                dict[num] = i        
     
        '''
        # 执行用时: 1368 ms......
        num = []
        for i in range(len(nums)):
            if (target-nums[i]) in nums:
                if nums.index(target-nums[i]) != i:
                    num.append(i)
                    num.append(nums.index(target-nums[i]))
                    break
        return num
        '''