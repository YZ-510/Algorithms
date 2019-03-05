# 字符串转整数 (atoi)
# https://leetcode-cn.com/problems/string-to-integer-atoi/

class Solution:
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        str = str.strip()
        n = ''
        positive = True
        if str == '':
            return 0
        if str[0] == '+' or str[0] == '-':
            if str[0] == '-':
                positive = False
            str = str[1:]
        for char in str:
            if '0' <= char <= '9':
                n = n + char
            else:
                break                
        '''
        n = 0
        for char in str:
            if '0' <= char <= '9':
                n = n * 10 + ord(char) - ord('0')
            else:
                break
        '''
        
        if n == '':
            return 0
        else:
            n = int(n)
        if n > 2147483647:
            if positive == False:
                return -2147483648
            else:
                return 2147483647
        if not positive:
            return 0 - n
        return n
