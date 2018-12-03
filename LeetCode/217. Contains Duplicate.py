class Solution:
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        num = set()
        for i in nums:
            if i not in num:
                num.add(i)
            else:
                return True
        return False
        
        
        """
        Temp = False
        nums.sort()
        for i in range(len(nums) - 1):
            if nums[i] == nums[i + 1]:
                Temp = True
        return Temp
        """
        
        """
        return len(set(nums)) != len(nums)
        """