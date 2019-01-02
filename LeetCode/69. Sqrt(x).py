# x 的平方根
# https://leetcode-cn.com/problems/sqrtx/

class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x == 0:
            return 0
        left = 0
        right = x
        mid = (left + right) // 2
        while left <= right:
            mid = (left + right) // 2
            if mid **2 == x:
                return mid
            elif mid ** 2 < x:
                left = mid + 1
            else:
                right = mid - 1
        return left -1