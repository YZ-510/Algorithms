# 同构字符串
# https://leetcode-cn.com/problems/isomorphic-strings/

class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        # 确保 s 和 t 是 isomorphic
        # 同时 t 和 s 也是 isomorphic
        
        return self.iso(s, t) and self.iso(t, s)
        
    def iso(self, s, t):
        dic = {}
        for i in range(len(s)):
            if s[i] not in dic:
                dic[s[i]] = t[i]
            elif s[i] in dic:
                if dic[s[i] != t[i]:
                    return False
        return True
        
        '''
        dic_s = {}
        dic_t = {}
        c = 0
        for i in range(len(s)):
            if s[i] not in dic_s:
                dic_s[s[i]] = i
        for j in range(len(t)):
            if t[j] not in dic_t:
                dic_t[t[j]] = j
            if dic_s[s[j]] != dic_t[t[j]]:
                return False
        return True
        '''
        '''
        return len(set(zip(s, t))) == len(set(s)) == len(set(t))
        '''