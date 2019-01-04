# Pow(x, n)
# https://leetcode-cn.com/problems/powx-n/

class Solution:
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        # 二分求幂
        
        if n == 0:
            return 1.0
        if n < 0:
            x = 1 / x
            n = -n
        if n % 2 == 0:
            return self.myPow(x*x, n//2)
        else:
            return self.myPow(x*x, n//2) * x
            
        '''
        if n == 0:
            return 1.0
        if n < 0:
            return 1 / self.myPow(x, -n)
        if n & 1:   # n 为奇数
            return x * self.myPow(x*x, n>>1)
        else:
            return self.myPow(x*x, n>>1)        
        '''