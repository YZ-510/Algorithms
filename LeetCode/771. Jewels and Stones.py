# 宝石与石头
# https://leetcode-cn.com/problems/jewels-and-stones/

class Solution(object):
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        n = 0
        dic = {}
        for char in J:
            dic[char] = 0
        for char in S:
            if char in dic:
                n += 1
        return n