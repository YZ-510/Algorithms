# 汉明距离
# https://leetcode-cn.com/problems/hamming-distance/

class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        # 先异或，再求 hamming distance
        
        return bin(x^y).count('1')
        
        '''
        dist = 0
        val = x ^ y
        while val:
            dist += 1
            val &= val - 1
        return dist        
        '''