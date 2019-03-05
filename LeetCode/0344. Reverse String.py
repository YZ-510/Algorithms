# 反转字符串
# https://leetcode-cn.com/problems/reverse-string/

class Solution:
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        
        return s[::-1]
        
        '''
        s = list(s)
        s.reverse()
        return ''.join(s)
        
        s = list(s)
        n = len(s)
        for i in range(n//2):
            s[i], s[n-1-i] = s[n-1-i], s[i]
        
        return ''.join(s)
        '''
