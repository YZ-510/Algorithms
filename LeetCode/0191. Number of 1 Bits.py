# 位1的个数
# https://leetcode-cn.com/problems/number-of-1-bits/

class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        # 转换成二进制，数 1 的个数
        
        return bin(n).count('1')