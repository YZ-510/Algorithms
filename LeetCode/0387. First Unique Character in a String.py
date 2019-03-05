# 字符串中第一个唯一字符
# https://leetcode-cn.com/problems/first-unique-character-in-a-string/

class Solution:
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        l = len(s)
        t = l
        for c in 'abcdefghijklmnopqrstuvwxyz':
            if s.count(c) == 1:
                i = s.index(c)
                # 判断是否为最小索引
                if i < t:
                    t = i                    
        if t == l:
            return -1
        else:
            return t
            
        
        '''
        dic = {}
        for i in s:
            try:
                dic[i] += 1
            except:
                dic[i] = 1
            
        for i in list(dic.keys()):
            if dic[i] > 1:
                dic.pop(i)
                
        for i in range(len(s)):
            if s[i] in dic:
                return i
        return -1
        
        
        for i in range(len(s)):
            if s[i] not in s[i+1:]:
                if s[i] not in s[:i]:
                    return i         
        return -1
        '''
