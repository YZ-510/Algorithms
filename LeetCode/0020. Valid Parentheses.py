# 有效的括号
# https://leetcode-cn.com/problems/valid-parentheses/

class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        '''
        出现右括号时，需要判断：stack 是否为空、左右括号是否对应
        最后需要判断 stack 是否为空
        '''
        leftP = '([{'
        rightP = '}])'
        stack = []
        for char in s:
            if char in leftP:
                stack.append(char)
            if char in rightP:
                if not stack:
                    return False
                tmp = stack.pop()
                if char == ')' and tmp != '(':
                    return False
                if char == ']' and tmp != '[':
                    return False
                if char == '}' and tmp != '{':
                    return False
        return stack == []
