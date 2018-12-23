# 逆波兰表达式求值(后缀表达式求值)
# https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/

class Solution:
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = []
        for t in tokens:
            if t not in '+-*/':
                stack.append(int(t))
            else:
                r, l = stack.pop(), stack.pop()
                if t == '+':
                    stack.append(l + r)
                elif t == '-':
                    stack.append(l - r)
                elif t == '*':
                    stack.append(l * r)
                else:
                    if l * r < 0 and l % r != 0:
                        stack.append(l // r + 1)
                    else:
                        stack.append(l // r)
                    # stack.append(int(float(l) / r))
        return stack.pop()