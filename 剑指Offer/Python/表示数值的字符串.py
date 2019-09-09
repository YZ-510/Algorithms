# 表示数值的字符串遵循模式 A[.[B]][e|EC] 或者 .B[e|EC]
# A 为整数部分，B 为小数部分，C 为指数部分
# A、C 都可以是以 +、- 开头的 0~9 的数位串，B 也是 0~9 的数位串，但前面不能有正负号

class Solution:
    # s字符串
    def isNumeric(self, s):
        # write code here
        if s == '':
            return False
        
        # 分别标记是否出现过正负号、小数点、e
        has_sign = False
        has_point = False
        has_e = False
        for i in range(len(s)):
            if s[i] == 'E' or s[i] == 'e':
                if has_e: # 出现两个 E
                    return False
                else:
                    has_e = True
                    if i == len(s) - 1: # E 不能出现在最后，E 后面要接数字
                        return False
            elif s[i] == '+' or s[i] == '-':
                if has_sign: # 如果已经出现过了符号位，那么这个符号位必须跟在 E 后面
                    if s[i-1] != 'e' and s[i-1] != 'E':
                        return False
                else: # 如果第一次出现符号位，且出现的位置不是字符串第一个位置，就只能出现在 E 后面
                    has_sign = True
                    if i > 0 and s[i-1] != 'e' and s[i-1] != 'E':
                        return False
            elif s[i] == '.':
                if has_point or has_e: # 小数点不能出现两次，且如果已经出现过 E，就不能再出现小数点
                    return False
                else: # 如果第一次出现小数点，但前面出现过 E，还是不能出现小数点
                    has_point = True
                    if i > 0 and (s[i-1] == 'e' or s[i-1] == 'E'):
                        return False
            else: # 其他字符必须是 '0' 到 '9' 之间
                if s[i] < '0' or s[i] > '9':
                    return False
        
        return True