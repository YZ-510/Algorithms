# 用循环的方式实现，把前两个数字存入一个数组中，一直更新这个数组
# f(n) = f(n-1) + f(n-2)

class Solution:
    def Fibonacci(self, n):
        # write code here
        temp = [0, 1, 2]
        if n < 2:
            return temp[n]
        for i in range(2, n+1):
            temp[2] = temp[1] + temp[0]
            temp[0], temp[1] = temp[1], temp[2]
        
        return temp[-1]


class Solution:
    def Fibonacci(self, n):
        # write code here
        temp = [0, 1]
        if n < 2:
            return temp[n]
        fibNMinusOne, fibNMinusTwo = 0, 1
        fibN = 0
        for i in range(2, n+1):
            fibN = fibNMinusTwo + fibNMinusOne
            fibNMinusOne, fibNMinusTwo = fibNMinusTwo, fibN
        
        return fibN