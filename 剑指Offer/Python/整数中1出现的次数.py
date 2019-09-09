# 累加 1~n 中每个整数 1 出现的次数，每次通过对 10 求余数判断整数的个位数字是不是 1。
# 如果数字大于 10，则除以 10 之后再判断个位数字是不是 1。

class Solution:
    def NumberOf1Between1AndN_Solution(self, n):
        # write code here
        count = 0
        for i in range(1, n+1):
            while i:
                if i % 10 == 1:
                    count += 1
                i = i / 10
        
        return  count