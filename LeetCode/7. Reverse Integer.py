# 整数反转
# https://leetcode-cn.com/problems/reverse-integer/

class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        def divide(x):
            m = x // 10
            n = x % 10
            return m, n

        a = 1  
        if x < 0:
            x = -1 * x
            a = -1
            
        num = []
        if x > 9:
            while x > 9:
                x, y = divide(x)
                num.append(y)
            num.append(x)
        else:
            return x * a
        
        num.reverse()
        n = 0
        for i in range(len(num)):
            n = num[i] * (10 ** i) + n
        n = a*n
        
        if n <= 2 ** 31-1 and n >= -2 ** 31:
            return n
        else:
            return 0