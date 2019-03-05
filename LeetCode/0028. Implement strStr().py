# 实现 strStr()
# https://leetcode-cn.com/problems/implement-strstr/

class Solution:
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        m = len(haystack)
        n = len(needle)
        
        if n == 0:
            return 0
        if n > m:
            return -1
        for i in range(m):
            if haystack[i] == needle[0]:
                # 判断 haystack 剩下的字符串长度是否大于等于 needle 的长度
                if i + n > m:
                    return -1
                if haystack[i+1:i+n] == needle[1:]:
                    return i

        if i == m - 1:
            return -1
