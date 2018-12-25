# 字符串解码
# https://leetcode-cn.com/problems/decode-string/

class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        # 栈，迭代
        # 时间复杂度：O(N)，空间复杂度：O(N)
        
        if not s or len(s) == 0:
            return ''
        stack = [['', 1]]
        num = 0
        for i, c in enumerate(s):
            if c.isdigit():
                num = num * 10 + int(c)
            elif c.isalpha():
                stack[-1][0] += c
            elif c == '[':
                stack.append(['', num])
                num = 0
            elif c == ']':
                prev_str, cnt = stack.pop()
                stack[-1][0] += prev_str * cnt
        return stack[0][0]
        
        '''
        # 递归
        # 时间复杂度：O(N)，空间复杂度：O(1)
        
        if not s or len(s) == 0:
            return ''
        
        def helper(s):
            res = ''
            open_idx = s.find('[')
            if open_idx != -1:
                open_cnt = 1
                idx = open_idx + 1
                while idx < len(s) and open_cnt > 0:    # 找到与第一个 '[' 匹配的 ']'
                    if s[idx] == '[':
                        open_cnt += 1
                    elif s[idx] == ']':
                        open_cnt -= 1
                    idx += 1
                close_idx = idx - 1
                tmp_str = ''
                cnt, i = 0, 0
                while i < open_idx and not s[i].isdigit():  # 找到数字前可能有的字符串
                    tmp_str += s[i]
                    i += 1
                cnt = int(s[i:open_idx])
                return tmp_str + cnt * helper(s[open_idx + 1:close_idx]) + helper(s[close_idx + 1:])
            else:
                return s
            
        return helper(s)        
        '''