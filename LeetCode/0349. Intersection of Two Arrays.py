# 两个数组的交集
# https://leetcode-cn.com/problems/intersection-of-two-arrays/

class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        if not nums1 or not nums2:
            return []
        return list(set(nums1) & set(nums2))
