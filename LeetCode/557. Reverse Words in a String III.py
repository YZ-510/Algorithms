# 反转字符串中的单词 III
# https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/

class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = s.split()
        result = []
        for string in s:
            string = string[::-1]
            result.append(string)
            
        return ' '.join(result)