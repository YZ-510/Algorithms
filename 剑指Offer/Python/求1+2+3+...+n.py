# 利用两个函数，一个函数充当递归函数，另一个函数处理终止递归的情况
# 如果对 n 连续两次做反运算，非零的 n 转换为 True，0 转换为 False

class Solution:
    def Sum_Solution(self, n):
        # write code here
        return self.sumN(n)
    
    def sum0(self, n):
        return 0
    
    def sumN(self, n):
        fun = {False: self.sum0, True: self.sumN}
        return n + fun[not not n](n - 1)