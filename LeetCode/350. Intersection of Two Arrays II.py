# 两个数的交集 II
# https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/

class Solution:
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        num = []
        for i in nums1:
            if i in nums2 and len(nums2)>0:
                num.append(i)
                nums2.remove(i)
                
        return num