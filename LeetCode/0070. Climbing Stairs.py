# 爬楼梯
# https://leetcode-cn.com/problems/climbing-stairs/

class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        # 采用 bottom up 思想，动态规划，时间复杂度：O(N)，空间复杂度：O(N)
        
        cache = [1] * (n+1)
        for i in range(2, n+1):
            cache[i] = cache[i-1] + cache[i-2]    
        return cache[-1]

'''
        # 时间复杂度：O(N)，空间复杂度：O(1)
        cache = [1, 2, 3]
        if n < 4:
            return cache[n-1]
        for i in range(3, n+1):
            cache[2] = cache[0] + cache[1]
            cache[0], cache[1] = cache[1], cache[2]
        return cache[2]

        
class Solution(object):
    cache = {1: 1, 2: 2}
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n in self.cache:
            return self.cache[n]
        self.cache[n] = self.climbStairs(n-1) + self.climbStairs(n-2)
        return self.cache[n]
'''