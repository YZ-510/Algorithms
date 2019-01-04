# 寻找两个有序数组的中位数
# https://leetcode-cn.com/problems/median-of-two-sorted-arrays/

class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        # 参考：https://github.com/apachecn/awesome-algorithm/blob/master/docs/Leetcode_Solutions/Python/004._median_of_two_sorted_arrays.md
        
        def findKth(A, B, k):
            if len(A) == 0:
                return B[k-1]
            if len(B) == 0:
                return A[k-1]
            if k == 1:
                return min(A[0], B[0])
            
            a = A[k // 2 - 1] if len(A) >= k // 2 else None
            b = B[k // 2 - 1] if len(B) >= k // 2 else None
            
            if b is None or (a is not None and a < b):
                return findKth(A[k // 2:], B, k - k // 2)
            return findKth(A, B[k // 2:], k - k // 2)
        
        n = len(nums1) + len(nums2)
        if n % 2 == 1:
            return findKth(nums1, nums2, n // 2 + 1)
        else:
            smaller = findKth(nums1, nums2, n // 2)
            bigger = findKth(nums1, nums2, n // 2 + 1)
            return (smaller + bigger) / 2