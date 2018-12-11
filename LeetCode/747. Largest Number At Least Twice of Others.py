class Solution(object):
    def dominantIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1:
            return 0
        num = sorted(nums)
        # 如果最大值 >= 次大值 * 2，返回最大值得索引，否则返回 -1
        if num[-1] >= num[-2]*2:
            return nums.index(num[-1])
        else:
            return -1