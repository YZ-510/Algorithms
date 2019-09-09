
class Solution:
    def Power(self, base, exponent):
        # write code here
        res = self.power_value(base, abs(exponent))
        if exponent < 0:
            return 1.0 / res
        
        return res
    
    def power_value(self, base, exponent):
        if exponent == 0:
            return 1
        if exponent == 1:
            return base
        res = 1
        for i in range(exponent):
            res *= base
        
        return res

    # 递归
    def power_value(self, base, exponent):
        if exponent == 0:
            return 1
        if exponent == 1:
            return base
        res = self.power_value(base, exponent >> 1) # 右移运算符代替了除以 2
        res *= res
        if exponent & 1 == 1: # 位与运算符代替了求余运算符 %
            res *= base
        
        return res