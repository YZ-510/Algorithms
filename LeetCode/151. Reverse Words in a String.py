# 翻转字符串中的单词
# https://leetcode-cn.com/problems/reverse-words-in-a-string/

class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        return ' '.join(s.split()[::-1])