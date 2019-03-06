# 罗马数字转整数
# https://leetcode-cn.com/problems/roman-to-integer/

class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        # 如果当前数比前一个大，说明这一段的值应当是当前值减去前一个值
        
        dic = {
            'I' : 1,
            'V' : 5,
            'X' : 10,
            'L' : 50,
            'C' : 100,
            'D' : 500,
            'M' : 1000
        }
        res = 0
        for i in range(len(s)):
            if i > 0 and dic[s[i]] > dic[s[i-1]]:
                res += dic[s[i]] - 2 * dic[s[i-1]]
            else:
                res += dic[s[i]]
        return res