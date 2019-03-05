# 无重复字符的最长子串
# https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        # 从第一个字符开始，只要碰到已经出现过的字符，就必须从之前出现该字符的 index+1 处开始重新往后判断
        # start 为未重复字符串首字母的 index
        # 只要字符 s[i] 在 dic 中的值大于等于 start，说明该字符已经出现过了，要充值 l 和 start 的值
        # 将 start + 1，即从后一位重新开始判断，然后比较目前的子串长度与之前的最大长度
        
        l, start = 0, 0
        dic = {}
        for i in range(len(s)):
            start = max(start, dic.get(s[i], -1) + 1)
            l = max(l, i - start + 1)
            dic[s[i]] = i
        return l
        
        '''
        lookup = {}
        start, end, counter, length = 0, 0, 0, 0
        while end < len(s):
            lookup[s[end]] = lookup.get(s[end], 0) + 1
            if lookup[s[end]] == 1:
                counter += 1
            end += 1
            while start < end and counter < end - start:
                lookup[s[start]] -= 1
                if lookup[s[start]] == 0:
                    counter -= 1
                start += 1
            length = max(length, end - start)
            
        return length        
        '''
