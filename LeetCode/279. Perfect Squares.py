# 完全平方数
# https://leetcode-cn.com/problems/perfect-squares/

class Solution:
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        # BFS
        temp = int(n**0.5)
        if temp**2 == n:
            return 1
        squs = [x**2 for x in range(1, temp + 1)]
        nums = [n - x for x in squs]
        i = 2
        while True:
            temp = set()
            for x in nums:
                for y in squs:
                    if x == y:
                        return i
                    elif x < y:
                        break
                    else:
                        temp.add(x - y)
            i += 1
            nums = temp
            
    '''
    # DP(dynamic programming) 动态规划
    
        if int(n**0.5)**2 == n:
            return 1
        dp = [0]
        for i in range(1, n + 1):
            dp.append(min(dp[-k * k] for k in range(1, int(i**0.5 + 1))) + 1)
            
        return dp[-1]    
    '''
    
    