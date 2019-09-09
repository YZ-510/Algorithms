# 把一个整数减去 1，再和原整数做与运算，会把该整数最右边的 1 变成 0
# 一个整数的二进制表示中有多少个 1 就可以进行多少次这样的操作

class Solution:
    def NumberOf1(self, n):
        # write code here
        count = 0
        if n < 0:
            n = n & 0xffffffff
        while n != 0:
            count += 1
            n = (n - 1) & n
        
        return count