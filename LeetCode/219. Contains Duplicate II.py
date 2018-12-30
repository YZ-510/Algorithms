# 存在重复元素 II
# https://leetcode-cn.com/problems/contains-duplicate-ii/

class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        if k == 0:
            return False
        
        # 若元素未在字典中，存进字典
        # 若该元素再次出现，计算相邻距离
        # 若相邻距离大于 k，更新字典中该元素的索引
        
        lookup = {}
        for i in range(len(nums)):
            if nums[i] not in lookup:
                lookup[nums[i]] = i
            else:
                if i - lookup[nums[i]] <= k:
                    return True
                else:
                    lookup[nums[i]] = i
        
        return False