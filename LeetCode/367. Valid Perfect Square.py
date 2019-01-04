# 有效的完全平方数
# https://leetcode-cn.com/problems/valid-perfect-square/

class Solution:
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        # 从 0 开始试，不行就加 1
        
        res = 0
        while res * res <= num:
            if res * res == num:
                return True
            res += 1
        return False
        
        '''
        # 牛顿法
        
        t = num
        while t * t > num:
            t = (t + num / t) / 2
        return t * t == num        
        '''
        '''
        # 等差数列法
        
        i = 1
        while num > 0:
            num -= i
            i += 2
        return num == 0        
        '''