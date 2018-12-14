# 验证回文串
# https://leetcode-cn.com/problems/valid-palindrome/

class Solution:
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # 双指针
        m, n = 0, len(s)-1
        while m < n:
            while m < n and not s[m].isalnum():
                m += 1
            while m < n and not s[n].isalnum():
                n -= 1
            if s[m].lower() != s[n].lower():
                return False
            m += 1
            n -= 1
        return True
        
        
        '''
        s = ''.join(i for i in s if i.isalnum()).lower()
        return s == s[::-1]
        
        
        n = ''
        s = s.lower()
        for i in s:
            if '0' <= i <= '9' or 'a' <= i <= 'z':
                n = n + i
                
        return n == n[::-1]
        '''