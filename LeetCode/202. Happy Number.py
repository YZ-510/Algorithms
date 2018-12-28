# 快乐数
# https://leetcode-cn.com/problems/happy-number/

class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        # 如果不是快乐数的话，继续计算的结果会重复出现
        
        s = set()
        while n != 1:
            num = 0
            for char in str(n):
                num = num + int(char) ** 2
            if num in s:
                return False
            s.add(num)
            n = num
            
        return True