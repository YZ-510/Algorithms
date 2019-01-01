# 四数相加 II
# https://leetcode-cn.com/problems/4sum-ii/

class Solution(object):
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        # 先对 A、B 能组成的和进行统计，然后对 C、D 遍历求和并取相反数
        # 看相反数在 AB 中出现了多少次
        # 时间复杂度：O(N^2)，空间复杂度：O(N^2)
        
        AB = collections.Counter(a + b for a in A for b in B)
        return sum(AB[-(c + d)] for c in C for d in D)
        
        '''
        dic = {}
        ans = 0
        for a in A:
            for b in B:
                if a + b not in dic:
                    dic[a + b] = 1
                else:
                    dic[a + b] += 1
        
        for c in C:
            for d in D:
                if -(c + d) in dic:
                    ans += dic[-(c + d)]
                    
        return ans        
        '''